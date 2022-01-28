#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <peekpoke.h>
#include <conio.h>
#include <joystick.h>

void main(void) {
    uint8_t a,j, err, ps_old, select_start, n_joy, c;
    ps_old = 0;
	n_joy = 1;
    POKE(0xD018, 21);  //switch to upper case mode

    clrscr();
	
	// Background and text
	bgcolor(0);
    textcolor(3);
    gotoxy(2, 1);
    printf("test 5+1 buttons joystick for cbm64");
    printf("\n\n\n\n                   %c%c     \n", 0x6e, 0x6d);
    printf("               %c        %c\n\n\n", 0x6f,  0x70);
    printf("              %c          %c\n", 0x6e,0x6d);
    printf("              %c          %c\n\n\n", 0x6d, 0x6e);
    printf("               %c        %c\n", 0x6c, 0xba);
    printf("                   %c%c     \n", 0x6d, 0x6e);
    cputcxy(13, 4, 0x75);
    cputcxy(14, 4, 0x60);
    cputcxy(15, 4, 0x60);
    cputcxy(16, 4, 0x60);
    cputcxy(17, 4, 0x60);
    cputcxy(18, 4, 0x60);
    cputcxy(19, 4, 0x60);
    cputcxy(20, 4, 0x60);
    cputcxy(21, 4, 0x60);
    cputcxy(22, 4, 0x60);
    cputcxy(23, 4, 0x60);
    cputcxy(24, 4, 0x60);
    cputcxy(25, 4, 0x60);
    cputcxy(26, 4, 0x69);
    cputcxy(13, 5, 0x62);
    cputcxy(13, 6, 0x62);
    cputcxy(13, 7, 0x62);
    cputcxy(13, 8, 0x62);
    cputcxy(13, 9, 0x62);
    cputcxy(13, 10, 0x62);
    cputcxy(13, 11, 0x62);
    cputcxy(13, 12, 0x62);
    cputcxy(13, 13, 0x62);
    cputcxy(13, 14, 0x62);
    cputcxy(13, 15, 0x6A);
    cputcxy(14, 15, 0x60);
    cputcxy(15, 15, 0x60);
    cputcxy(16, 15, 0x60);
    cputcxy(17, 15, 0x60);
    cputcxy(18, 15, 0x60);
    cputcxy(19, 15, 0x60);
    cputcxy(20, 15, 0x60);
    cputcxy(21, 15, 0x60);
    cputcxy(22, 15, 0x60);
    cputcxy(23, 15, 0x60);
    cputcxy(24, 15, 0x60);
    cputcxy(25, 15, 0x60);
    cputcxy(26, 15, 0x6B);
    cputcxy(26, 5, 0x62);
    cputcxy(26, 6, 0x62);
    cputcxy(26, 7, 0x62);
    cputcxy(26, 8, 0x62);
    cputcxy(26, 9, 0x62);
    cputcxy(26, 10, 0x62);
    cputcxy(26, 11, 0x62);
    cputcxy(26, 12, 0x62);
    cputcxy(26, 13, 0x62);
    cputcxy(26, 14, 0x62);
    gotoxy(0, 0);
    textcolor(1);
    cputcxy(0, 0, 0x6F);
    for (a = 1; a < 39; a++) {
        cputcxy(a, 0, 0xB7);
    }
    cputcxy(39, 0, 0x70);
    for (a = 1; a < 24; a++) {
        cputcxy(0, a, 0xA5);
        cputcxy(39, a, 0xAA);
    }
    for (a = 1; a < 39; a++) {
        cputcxy(a, 24, 0xAF);
    }
    cputcxy(0, 24, 0x6C);
    cputcxy(39, 24, 0xBA);
    gotoxy(10, 17);
    textcolor(3);
    printf("select         start");
    gotoxy(3, 20);
    printf("fire a        fire b        fire c");

	textcolor(14);
	revers(1);
	cputcxy(3, 8, 0xE9);
	cputcxy(4, 8, 0xA0);
	cputcxy(5, 8, 0xA0);
	cputcxy(3, 9, 0xA0);
	cputcxy(3, 10, 0xA0);
	revers(0);
	cputcxy(3, 11, 0x7F);
	revers(1);
	cputcxy(4, 11, 0xA0);
	cputcxy(5, 11, 0xA0);
	cputcxy(6, 9, 0xA0);
	revers(0);
	cputcxy(7, 9, 0xE9);
	revers(1);
	textcolor(2);
	cputcxy(6, 10, 0xA0); 
	cputcxy(7, 10, 0x7F);
	textcolor(11);
	revers(0);
	cputcxy(4, 9, 0xA5);
	cputcxy(4, 10, 0xA5);
	cputcxy(6, 8, 0xA5);
	cputcxy(6, 11, 0xA5);
	textcolor(14);
	cputcxy(31, 8, 0x6F);
	cputcxy(32, 8, 0xB7);
	cputcxy(31, 9, 0xB4);
	cputcxy(31, 9, 0xB4);
	cputcxy(31, 10, 0x6F);
	cputcxy(32, 10, 0x70);
	cputcxy(31, 11, 0x6C);
	cputcxy(32, 11, 0xBA);
	
	cputcxy(35, 8, 0x6E);
	cputcxy(36, 8, 0xA5);
	cputcxy(34, 9, 0x6E);
	cputcxy(35, 9, 0x20);
	cputcxy(36, 9, 0xA5);
	cputcxy(34, 10, 0xB7);
	cputcxy(35, 10, 0xB7);
	cputcxy(36, 10, 0xA5);
	cputcxy(36, 11, 0xA5);
	
	textcolor(11);
	gotoxy(10, 3);
    printf("press return to exit");
	gotoxy(5, 23);
	printf("press j to change joystick(# )");
	textcolor(1); 


    err = joy_install(joy_static_stddrv);
    if (err != JOY_ERR_OK) {
        printf("Error :%d\n",err);
		exit(0);
    }

    while (1) {

	   POKE(0xDC0D,127); // REM TURN OFF KBD
       j = joy_read(n_joy);
       select_start = 0;
		
		if (ps_old != 1) {
           cputcxy(16, 7, ' ');
           cputcxy(17, 7, ' ');
           cputcxy(16, 8, ' ');
           cputcxy(17, 8, ' ');
		}
		if (ps_old != 3) {
           cputcxy(22, 7, ' ');
           cputcxy(23, 7, ' ');
           cputcxy(22, 8, ' ');
           cputcxy(23, 8, ' ');
		}
		if (ps_old != 2) {
           cputcxy(19, 6, ' ');
           cputcxy(20, 6, ' ');
           cputcxy(19, 7, ' ');
           cputcxy(20, 7, ' ');
		}
		if (ps_old != 7) {
           cputcxy(16, 11, ' ');
           cputcxy(17, 11, ' ');
           cputcxy(16, 12, ' ');
           cputcxy(17, 12, ' ');
		}
		if (ps_old != 4) {
           cputcxy(15, 9, ' ');
           cputcxy(16, 9, ' ');
           cputcxy(15, 10, ' ');
           cputcxy(16, 10, ' ');
		}
		if (ps_old != 9) {
           cputcxy(22, 11, ' ');
           cputcxy(23, 11, ' ');
           cputcxy(22, 12, ' ');
           cputcxy(23, 12, ' ');
		}
		if (ps_old != 6) {
           cputcxy(23, 9, ' ');
           cputcxy(24, 9, ' ');
           cputcxy(23, 10, ' ');
           cputcxy(24, 10, ' ');
		}
		if (ps_old != 8) {
           cputcxy(19, 12, ' ');
           cputcxy(20, 12, ' ');
           cputcxy(19, 13, ' ');
           cputcxy(20, 13, ' ');
		}
		if (ps_old != 5) {
           cputcxy(19, 9, ' ');
           cputcxy(20, 9, ' ');
           cputcxy(19, 10, ' ');
           cputcxy(20, 10, ' ');
		}
		if (JOY_BTN_1(j)) 
           textcolor(5); //Char color
		cputcxy(5, 21, 0x75);
		cputcxy(6, 21, 0x69);
		cputcxy(5, 22, 0x6a);
		cputcxy(6, 22, 0x6b);
		POKE(646, 1); //Char color
       
		POKE(0xDC00,64 * (n_joy +1)); // REM SWITCH POT
		if (PEEK(0xD41A) < 8) 
           textcolor(5); //Char color
		cputcxy(33, 21, 0x75);
		cputcxy(34, 21, 0x69);
		cputcxy(33, 22, 0x6a);
		cputcxy(34, 22, 0x6b);
		POKE(646, 1); //Char color

		POKE(0xDC00,64 * (n_joy +1)); // REM SWITCH POT
		if (PEEK(0xD419) < 8) 
           textcolor(5); //Char color
		cputcxy(19, 21, 0x75);
		cputcxy(20, 21, 0x69);
		cputcxy(19, 22, 0x6a);
		cputcxy(20, 22, 0x6b);
		POKE(646, 1); //Char color

		if (JOY_UP(j) && JOY_DOWN(j)) {  //Check "select" combination
				textcolor(5);
				select_start = 1;
				ps_old = 5;
		}
		cputcxy(12, 18, 0x75);
		cputcxy(13, 18, 0x69);
		cputcxy(12, 19, 0x6a);
		cputcxy(13, 19, 0x6b);
		POKE(646, 1);
		
		if (JOY_LEFT(j) && JOY_RIGHT(j)) { //Check "start" combination
				textcolor(5);
				select_start = 1;
				ps_old = 5;
		}
		cputcxy(26, 18, 0x75);
		cputcxy(27, 18, 0x69);
		cputcxy(26, 19, 0x6a);
		cputcxy(27, 19, 0x6b);
		POKE(646, 1);


	   
		if (select_start) {
			cputcxy(19, 9, 0x75);
			cputcxy(20, 9, 0x69);
			cputcxy(19, 10, 0x6a);
			cputcxy(20, 10, 0x6b);
			continue;
		}
		
		if (JOY_UP(j)) {
           
			if (JOY_UP(j) && JOY_LEFT(j)) {
				   if (ps_old != 1) {
					   ps_old = 1;
					   cputcxy(16, 7, 0x75);
					   cputcxy(17, 7, 0x69);
					   cputcxy(16, 8, 0x6a);
					   cputcxy(17, 8, 0x6b);
				   }
				   continue;
			}
			if (JOY_UP(j) && JOY_RIGHT(j))  {
					if (ps_old != 3) {
                        ps_old = 3;
                        cputcxy(22, 7, 0x75);
                        cputcxy(23, 7, 0x69);
                        cputcxy(22, 8, 0x6a);
                        cputcxy(23, 8, 0x6b);
                    }
                    continue;
            }
           
            if (ps_old != 2) {
                   ps_old = 2;
                   cputcxy(19, 6, 0x75);
                   cputcxy(20, 6, 0x69);
                   cputcxy(19, 7, 0x6a);
                   cputcxy(20, 7, 0x6b);
               }
            continue;
           
		}

		
		if (JOY_LEFT(j)) {
			
			if (JOY_LEFT(j) && JOY_DOWN(j)) {
				if (ps_old != 7) {
				   ps_old = 7;
				   cputcxy(16, 11, 0x75);
				   cputcxy(17, 11, 0x69);
				   cputcxy(16, 12, 0x6a);
				   cputcxy(17, 12, 0x6b);
				}
				continue;
			}
		
			if (ps_old != 4) {
                ps_old = 4;
                cputcxy(15, 9, 0x75);
                cputcxy(16, 9, 0x69);
                cputcxy(15, 10, 0x6a);
                cputcxy(16, 10, 0x6b);
			}
			continue;  
		}
		
				
		if (JOY_RIGHT(j)) {
			if (JOY_RIGHT(j) && JOY_DOWN(j)) {
               if (ps_old != 9) {
                   ps_old = 9;
                   cputcxy(22, 11, 0x75);
                   cputcxy(23, 11, 0x69);
                   cputcxy(22, 12, 0x6a);
                   cputcxy(23, 12, 0x6b);
               }
               continue;
			}
           
			if (ps_old != 6) {
                   ps_old = 6;
                   cputcxy(23, 9, 0x75);
                   cputcxy(24, 9, 0x69);
                   cputcxy(23, 10, 0x6a);
                   cputcxy(24, 10, 0x6b);
            }
            continue;
           
		}
		if (JOY_DOWN(j)) {
           if (ps_old != 8) {
               ps_old = 8;
               cputcxy(19, 12, 0x75);
               cputcxy(20, 12, 0x69);
               cputcxy(19, 13, 0x6a);
               cputcxy(20, 13, 0x6b);
           }
           continue;
		}
       
		if (ps_old != 5) {
           ps_old = 5;
           cputcxy(19, 9, 0x75);
           cputcxy(20, 9, 0x69);
           cputcxy(19, 10, 0x6a);
           cputcxy(20, 10, 0x6b);
		}
       
		POKE(0xDC0D,129); // REM TURN ON KBD

		if(kbhit()) {
			c = cgetc();
			if (c == 74) {  //Switch Joystick on Space
				n_joy = n_joy ^ 1;
			}
			else if (c == 13) {  //Exit on Return
				clrscr();
				POKE(0xD018, 22);  //switch to lower case mode
				printf("\n     \"See you, Space Cowboy...\"\n\n\nCrystalCT Retro Production\n\n");
				exit(0);
			}
		} 
		cputcxy(33, 23, 0x31 + n_joy);
		POKE(0xDC00,128); // REM SWITCH POT#2
    }
	
}