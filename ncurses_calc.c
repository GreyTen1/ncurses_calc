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
	printw("####  +  ####  - ######  *  ####  /  #####\n");
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
    move(6, 21);
    char c;
    while (ch != KEY_ESC)
    {

        ch = getch();

        if(ch == KEY_UP)
        {
            getyx(stdscr, y, x);
             move(y + -1 , x );
        }


        if(ch == KEY_DOWN)
        {
            getyx(stdscr, y, x);
             move(y + 1 , x );
        }

        if(ch == KEY_LEFT)
        {
            getyx(stdscr, y, x);
             move(y , x - 1 );
        }

        if(ch == KEY_RIGHT)
        {
            getyx(stdscr, y, x);
             move(y , x + 1 );
        }

        if(ch == '\n' || ch == '\r')
        {
            chtype ch = inch();
            c = ch & A_CHARTEXT;
            move( 20, 20);
            printw("%c", c);
        }

        refresh();
    }
   	refresh();
	endwin();
	return 0;
}
