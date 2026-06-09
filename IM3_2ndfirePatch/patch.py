import os
import binascii
import sys

# Target binary, output, and patch files
TARGET_FILE = "IM3_ICON64.bin"
OUTPUT_FILE = "IM3_ICON64_path.bin"
PATCH_FILE = "IM3.patch"

# ANSI colors
GREEN = "\033[92m"
RED = "\033[91m"
ORANGE = "\033[38;5;208m"
RESET = "\033[0m"

# Enable Windows virtual terminal processing for ANSI escape sequences in standard command prompt
if sys.platform == "win32":
    try:
        import ctypes
        kernel32 = ctypes.windll.kernel32
        # ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004
        # Get standard output handle: STD_OUTPUT_HANDLE = -11
        stdout_handle = kernel32.GetStdHandle(-11)
        mode = ctypes.c_ulong()
        if kernel32.GetConsoleMode(stdout_handle, ctypes.byref(mode)):
            kernel32.SetConsoleMode(stdout_handle, mode.value | 0x0004)
    except Exception:
        pass

def main():
    # Step 1: Check if target and patch files exist
    print("Step 1: Checking if target and patch files exist...")
    if not os.path.exists(TARGET_FILE):
        print(f"{RED}Result: Failed - {TARGET_FILE} not found.{RESET}")
        sys.exit(1)
    if not os.path.exists(PATCH_FILE):
        print(f"{RED}Result: Failed - {PATCH_FILE} not found.{RESET}")
        sys.exit(1)
    print("Result: Success - Both files found.\n")

    # Step 2a: Read target file and check CRC32
    print("Step 2a: Checking CRC32 of target file (IEEE 802.3)...")
    with open(TARGET_FILE, "rb") as f:
        data = bytearray(f.read())
    
    crc32_val = binascii.crc32(data) & 0xffffffff
    expected_crc = 0x19176BAB
    
    if crc32_val != expected_crc:
        print(f"{RED}Result: Failed - CRC32 mismatch for {TARGET_FILE} (Expected: 0x{expected_crc:08X}, Got: 0x{crc32_val:08X}).{RESET}")
        sys.exit(1)
    print(f"Result: Success - {TARGET_FILE} CRC32 matches expected value 0x{expected_crc:08X}.\n")

    # Step 2b: Read patch file and check CRC32
    print("Step 2b: Checking CRC32 of patch file (IEEE 802.3)...")
    with open(PATCH_FILE, "rb") as f:
        patch_data = f.read()
        
    patch_crc32 = binascii.crc32(patch_data) & 0xffffffff
    expected_patch_crc = 0xB0E1441D
    
    if patch_crc32 != expected_patch_crc:
        print(f"{RED}Result: Failed - CRC32 mismatch for {PATCH_FILE} (Expected: 0x{expected_patch_crc:08X}, Got: 0x{patch_crc32:08X}).{RESET}")
        sys.exit(1)
    print(f"Result: Success - {PATCH_FILE} CRC32 matches expected value 0x{expected_patch_crc:08X}.\n")

    # Step 3: Patch at offset $00019
    # Change 3 bytes: $20 $50 $FD -> $4C $50 $81
    print("Step 3: Patching 3 bytes at offset $00019 ($20 $50 $FD -> $4C $50 $81)...")
    offset_1 = 0x00019
    expected_1 = b"\x20\x50\xfd"
    replacement_1 = b"\x4c\x50\x81"
    
    if data[offset_1:offset_1+3] == expected_1:
        data[offset_1:offset_1+3] = replacement_1
        print("Result: Success - Bytes at $00019 patched successfully.")
    else:
        actual_1 = data[offset_1:offset_1+3].hex()
        print(f"{RED}Result: Failed - Expected bytes {expected_1.hex()} at $00019, but found {actual_1}.{RESET}")
        sys.exit(1)
    print()

    # Step 4: Patch at offset $024D1
    # Change 4 bytes: $A9 $04 $24 $81 -> $4C $40 $03 $EA
    print("Step 4: Patching 4 bytes at offset $024D1 ($A9 $04 $24 $81 -> $4C $40 $03 $EA)...")
    offset_2 = 0x024D1
    expected_2 = b"\xa9\x04\x24\x81"
    replacement_2 = b"\x4c\x40\x03\xea"
    
    if data[offset_2:offset_2+4] == expected_2:
        data[offset_2:offset_2+4] = replacement_2
        print("Result: Success - Bytes at $024D1 patched successfully.")
    else:
        actual_2 = data[offset_2:offset_2+4].hex()
        print(f"{RED}Result: Failed - Expected bytes {expected_2.hex()} at $024D1, but found {actual_2}.{RESET}")
        sys.exit(1)
    print()

    # Step 5: Patch at offset $024Fe
    # Change 4 bytes: $A9 $08 $24 $81 -> $4C $91 $03 $EA
    print("Step 5: Patching 4 bytes at offset $024Fe ($A9 $08 $24 $81 -> $4C $91 $03 $EA)...")
    offset_3 = 0x024FE
    expected_3 = b"\xa9\x08\x24\x81"
    replacement_3 = b"\x4c\x91\x03\xea"
    
    if data[offset_3:offset_3+4] == expected_3:
        data[offset_3:offset_3+4] = replacement_3
        print("Result: Success - Bytes at $024Fe patched successfully.")
    else:
        actual_3 = data[offset_3:offset_3+4].hex()
        print(f"{RED}Result: Failed - Expected bytes {expected_3.hex()} at $024Fe, but found {actual_3}.{RESET}")
        sys.exit(1)
    print()

    # Step 6: Overwrite from offset $00150 with content from IM3.patch
    print("Step 6: Overwriting data at offset $00150 with content of IM3.patch...")
    patch_len = len(patch_data)
    # Perform the overwrite
    data[0x00150:0x00150+patch_len] = patch_data
    print(f"Result: Success - Overwrote {patch_len} bytes starting at offset $00150.")
    print()

    # Step 7: Write back modified content to IM3_ICON64_path.bin
    print(f"Step 7: Saving patched file to {OUTPUT_FILE}...")
    try:
        with open(OUTPUT_FILE, "wb") as f:
            f.write(data)
        print("Result: Success - Patched file saved successfully.")
    except Exception as e:
        print(f"{RED}Result: Failed - Could not save file: {e}{RESET}")
        sys.exit(1)
    print()

    # Final success message in green
    print(f"{GREEN}The file has been patched successfully!{RESET}")
    print(f"{ORANGE}Be careful, if your secret agent starts jumping non-stop... Congratulations! Your SID replacement sucks. Not only does it not handle the POTX and POTY registers, but reading them doesn't return the standard $FF values at rest, but $00. Money well spent!{RESET}")

if __name__ == "__main__":
    main()
