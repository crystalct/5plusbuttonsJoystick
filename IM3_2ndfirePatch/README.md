# Instructions for applying the patch to YOUR copy of Imposible Mission 3

Choose a folder and put your **IM3_ICON64.crt**, **cartconv.exe** from the VICE emulator bin folder, the **IM3.patch** and **patch.py** ​​files inside.
Open the DOS shell (command prompt) and position yourself in the chosen folder.
Run the following commands in succession:
```
cartconv -i IM3_ICON64.crt -o IM3_ICON64.bin
```
```
python patch.py
```
```
cartconv -t md -i IM3_ICON64_path.bin -o IM3_ICON64_path.crt
```

*Be careful, if your secret agent starts jumping non-stop... Congratulations! Your SID replacement sucks. Not only does it not handle the POTX and POTY registers, but reading them doesn't return the standard $FF values at rest, but $00. Money well spent!*

**Download**
[patch.py]()
[IM3.patch]()

