#include <ncurses.h>


const int KEY_ESC = 27;

void calc_display()
{
   	printw("##########################################\n");
	printw("##                                      ##\n");
	printw("##########################################\n");
	printw("##########################################\n");
	printw("##  1  ###########  2  ############  3  ##\n");
	printw("##########################################\n");
	printw("##  4  ###########  5  ############  6  ##\n");
	printw("##########################################\n");
	printw("##  7  ###########  8  ############  9  ##\n");
	printw("##########################################\n");
	printw("##################  0  ###################\n");
	printw("##########################################\n");
	printw("###  +  ####  - ##  =  ##  *  ####  /  ###\n");
	printw("##########################################\n");
}

int main()
{

    initscr();
    keypad(stdscr, TRUE);
    noecho();
    set_escdelay(0);

    int y, x;

    int ch = -1;


   	refresh();
    calc_display();
    getyx(stdscr, y, x);
    move(6, 20);
    char c;
    while (ch != KEY_ESC)
    {

        ch = getch();

        if(ch == KEY_UP)
        {
            getyx(stdscr, y, x);
             move(y - 1 , x );

              chtype ch = inch();
              c = ch & A_CHARTEXT;

              while(c == '#' || c == ' ')
              {

                  getyx(stdscr, y, x);
                  move(y - 1 , x );
                  chtype ch = inch();
                  c = ch & A_CHARTEXT;
              }
        }


        if(ch == KEY_DOWN)
        {
            getyx(stdscr, y, x);

            move(y + 1 , x );
             chtype ch = inch();
             c = ch & A_CHARTEXT;

             while(c == '#' || c == ' ')
             {

                 getyx(stdscr, y, x);
                 move(y + 1 , x );
                 chtype ch = inch();
                 c = ch & A_CHARTEXT;
             }
        }

        if(ch == KEY_LEFT)
        {
            getyx(stdscr, y, x);

            if(x > 3){
                move(y , x - 1 );
                chtype ch = inch();
                c = ch & A_CHARTEXT;

                while(c == '#' || c == ' ')
                {

                    getyx(stdscr, y, x);
                    move(y , x - 1 );
                    chtype ch = inch();
                    c = ch & A_CHARTEXT;

                    getyx(stdscr, y, x);
                    if(x == 3){
                        break;
                    }
                }
            }

             refresh();
        }

        if(ch == KEY_RIGHT)
        {
            getyx(stdscr, y, x);
             move(y , x + 1 );
             chtype ch = inch();
             c = ch & A_CHARTEXT;

             while(c == '#' || c == ' ')
             {

                 getyx(stdscr, y, x);
                 move(y , x + 1 );
                 chtype ch = inch();
                 c = ch & A_CHARTEXT;
             }
             refresh();
        }

        if(ch == '\n' || ch == '\r') // enter was pressed
        {
            chtype ch = inch();
            c = ch & A_CHARTEXT;

            getyx(stdscr, y, x);

            int prev_y = y;
            int prev_x = x;

            move( 1, 37);
            printw("%c", c);
            move(prev_y,prev_x);
        }

        if(ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' )
        {
            getyx(stdscr, y, x);

            int prev_y = y;
            int prev_x = x;

            move( 1, 37);
            printw("%c", ch);
            move(prev_y,prev_x);
        }

        refresh();
    }
   	refresh();
	endwin();
	return 0;
}
