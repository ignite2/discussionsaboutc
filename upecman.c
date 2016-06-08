/***************************************************************************
 *   upecman.c                                Version 20160529.013231      *
 *                                                                         *
 *   Pacman Ncurses                                                        *
 *   Copyright (C) 2016         by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file upecman.c
 * @ingroup GroupUnique
 * @brief Pacman Ncurses
 * @details This program really do a nice job as a template, and template only!
 * @version 20160529.013231
 * @date 2016-05-29
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *      $make
 * ou
 *      $gcc upecman.c -o upecman.x -Wall -lncurses -g -Og
 *          -Wextra -ansi -pedantic-errors -DDEBUG=1
 */

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <ncurses.h> /* Screen handling and optimisation functions */
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include <assert.h> /* Verify assumptions with assert */
#include <unistd.h> /* UNIX standard function */
#include "upecman.h" /* To be created for this template if needed */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./upecman -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */


int main(int argc, char *argv[])
{
  IFDEBUG("main()\n");
  int joganterior=KEY_LEFT,jogatual;
  int opt; /* return from getopt() */
  t_game g; /* the game */
  const char *sready="Are you ready? (y/n)"; /* ready string */
  int kin; /* keyboard input */

  IFDEBUG("Starting optarg loop...\n");

  /* getopt() configured options:
   *        -h  help
   *        -c  copyright & version
   *        -v  verbose
   */
  opterr = 0;
  while((opt = getopt(argc, argv, "hvc")) != EOF)
    switch(opt)
    {
      case 'h':
        help();
        break;
      case 'v':
        verb++;
        break;
      case 'c':
        copyr();
        break;
      case '?':
      default:
        printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

  if(verb)
    printf("Verbose level set at: %d\n", verb);

  /* ...and we are done */
  IFDEBUG("Starting the game now...\n");

  g=upecman_init();

  printlab(g);

  mvprintw(10, 25, "%s", sready);
  refresh();
  

  int pacx,pacy;
  while(1)
  {

      debugPacman(g);
    
      kin=getch();
  //----------------
  //    if(kin=='y' || kin==KEY_LEFT)
  //        break;
  //----------------
     
      usleep(506667); /*wait 16666 microseconds to avoid frying the processor (1/60 s) */

      usleep(100000);

      if(kin=='s'){
          break;
      }
  //  g=pacman(g,&joganterior,&jogatual);
      g = andapac(g,kin);
  
      g = moveFantasmas(g);
      printlab(g);


  }
  /* write your code here */
 


  endwin();
  
  return EXIT_SUCCESS;
}


/**
 *
 */
t_game moveFantasmas(t_game jogo){

 jogo = moveFantasma1(jogo);
 jogo = moveFantasma2(jogo);
  //jogo = moveFantasma3(jogo);
 // jogo = moveFantasma4(jogo);

  return jogo;
}

/**
 * Move fantasma 1
 */
t_game moveFantasma1(t_game jogo)
{
    int fantasma = inky;

    int direcao = jogo.ghost[fantasma].dir;
    int xAtual = jogo.ghost[fantasma].pos.x; 
    int proximoX = 0;
    int proximoY = 0;

    if(direcao == right){
       proximoX = xAtual + 1;
       if( proximoX >= LABC) {
          direcao = left;
          proximoX = xAtual - 1;
       }
    }else if(direcao == left){
       proximoX = xAtual - 1;
       if( proximoX <= 1) {
          direcao = right;
          proximoX = xAtual + 1;
       }
    }else if(direcao == down){
    
    }
    
    proximoY = jogo.ghost[fantasma].pos.y;

    // Criando nova posicao
    t_pos novaPosicao; 
    novaPosicao.x = proximoX;
    novaPosicao.y = proximoY; 

    // atribuindo a nova posicao ao fantasma blinky
    jogo.ghost[fantasma].dir = direcao;
    jogo.ghost[fantasma].pos = novaPosicao; 
    
    return jogo;
}

/**
 * Move fantasma 1
 */
t_game moveFantasma2(t_game jogo)
{
    int fantasma = pinky;

    int direcao = jogo.ghost[fantasma].dir;
    int xAtual = jogo.ghost[fantasma].pos.x; 
    int yAtual = jogo.ghost[fantasma].pos.y; 
    int proximoX = 0;
    int proximoY = 0;
    int x = rand() % 4;

    if(direcao == right){
       proximoX = xAtual + 1;
       proximoY = yAtual;
       int foiPraParede = isParede (  jogo, proximoX, proximoY  );
       if( foiPraParede ){
           proximoX = xAtual;
           direcao = down;
           direcao = x;
       }
    }else if(direcao == left){
        proximoX = xAtual - 1;
        proximoY = yAtual;
        int foiPraParede = isParede (  jogo, proximoX, proximoY  );
        if( foiPraParede ){
             proximoX = xAtual;
             direcao = up;
             direcao = x;
        }
    }else if(direcao == up){
        proximoX = xAtual;
        proximoY = yAtual - 1;
        int foiPraParede = isParede (  jogo, proximoX, proximoY  );
        if( foiPraParede ){
            proximoY = yAtual;
            direcao = right;
            direcao = x;
       }

    }else if(direcao == down){
         proximoX = xAtual;
         proximoY = yAtual + 1;
         int foiPraParede = isParede (  jogo, proximoX, proximoY  );
         if( foiPraParede ){
               proximoY = yAtual;
               direcao = left;
               direcao = x;
         }
    }
   


    // Criando nova posicao
    t_pos novaPosicao; 
    novaPosicao.x = proximoX;
    novaPosicao.y = proximoY; 

    // atribuindo a nova posicao ao fantasma blinky
    jogo.ghost[fantasma].dir = direcao;  
    jogo.ghost[fantasma].pos = novaPosicao; 
   

    return jogo;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void help(void)
{
  IFDEBUG("help()");
  printf("%s - %s\n", "upecman", "Pacman Ncurses");
  printf("\nUsage: ./%s [-h|-v|-c]\n", "upecman");
  printf("\nOptions:\n");
  printf("\t-h,  --help\n\t\tShow this help.\n");
  printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
  printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
  /* add more options here */
  printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
  printf("\nTodo:\n\tLong options not implemented yet.\n");
  printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
  exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160529.013231
 * @date 2016-05-29
 *
 */
void copyr(void)
{
  IFDEBUG("copyr()");
  printf("%s - Version %s\n", "upecman", VERSION);
  printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software:  you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
  if(verb>3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
  exit(EXIT_FAILURE);
}

//* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
t_game upecman_init(void)
{
  IFDEBUG("init()");
  /* initialization */

  t_game g;
  int f, y;

  for(y=0; y<LABL; y++)
    strcpy(g.lab[y], labmodel[y]); /* copy the labyrinth (lines of strings) */

  g.pacman.pos.y=17; /* pacman start position (line) */
  g.pacman.pos.x=9; /* pacman start position (column) */
  g.pacman.dir=left; /* pacman start direction */
  g.pacman.life=3; /* 3 lifes */
  g.pacman.score=0; /* 0 points */

  for(f=blinky; f<=clyde; f++) /* blinky, pinky, inky and clyde */
  {
    switch(f)
    {
      case blinky:
        g.ghost[f].pos.y=3;//7; /* blinky start position (line) */
        g.ghost[f].pos.x=9; /* blinky start position (column) */
        g.ghost[f].starget.y=0; /* preferred corner (line) */
        g.ghost[f].starget.x=19; /* preferred corner (column) */
        break;
      case pinky:
        g.ghost[f].pos.y = 1; //9; /* pinky start position (line) */
        g.ghost[f].pos.x = 1; //10; /* pinky start position (column) */
        g.ghost[f].starget.y=0; /* preferred corner (line) */
        g.ghost[f].starget.x=0; /* preferred corner (column) */
        break;
      case inky:
        g.ghost[f].pos.y=10; /* inky start position (line) */
        g.ghost[f].pos.x=10; /* inky start position (column) */
        g.ghost[f].starget.y=22; /* preferred corner (line) */
        g.ghost[f].starget.x=19; /* preferred corner (column) */
        break;
      case clyde:
        g.ghost[f].pos.y=11; /* clyde start position (line) */
        g.ghost[f].pos.x=10; /* clyde start position (column) */
        g.ghost[f].starget.y=22; /* preferred corner (line) */
        g.ghost[f].starget.x=0; /* preferred corner (column) */
    }
    g.ghost[f].dir=right; /* start direction and future direction: left */
    g.ghost[f].mode=chase;
  }

  initscr(); /* start ncurses mode screen */
  cbreak(); /* stop line buffering */
  keypad(stdscr, TRUE); /* grab extended keys */
  noecho(); /* stop echoing chars */
  timeout(0); /* do not wait */
  start_color(); /* initialize the color functionality */

  /* Initialize all the colors */
  init_pair(1, COLOR_RED, COLOR_BLACK); /* Blinky */
  init_pair(2, COLOR_MAGENTA, COLOR_BLACK); /* Pinky */
  init_pair(3, COLOR_CYAN, COLOR_BLACK); /* Inky */
  init_pair(4, COLOR_GREEN, COLOR_BLACK); /* Clyde doesn't have orange :( */
  init_pair(5, COLOR_BLUE, COLOR_BLACK); /* Afraid mode: blue with A_BLINK */
  init_pair(6, COLOR_GREEN, COLOR_BLACK); /* Pacman */

  return g;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
void printlab(t_game g)
{
  IFDEBUG("printlab()");

  int y, f;

  clear(); /* clear the screen */
  for(y=0; y<LABL; y++)
    printw("%s\n", g.lab[y]);

  for(f=blinky; f<=clyde; f++) /* blinky, pinky, inky and clyde */
    mvchgat(g.ghost[f].pos.y, g.ghost[f].pos.x, 1, A_BOLD, f+1, NULL);  
 
  mvchgat(g.pacman.pos.y, g.pacman.pos.x, 1, A_BOLD, 6, NULL);  
  mvprintw(g.pacman.pos.y, g.pacman.pos.x,"@");  
  
  refresh();
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160530.224016
 * @date 2016-05-30
 *
 */
t_game pacman(t_game g, int *joganterior, int *jogatual)
{
  int leitura; 
  int pacx,pacy;

  pacx = g.pacman.pos.x;
  pacy = g.pacman.pos.y;
  leitura=getch();
 // if(leitura==KEY_RIGHT || leitura==KEY_LEFT || leitura==KEY_UP || leitura==KEY_DOWN )
   // *jogatual=leitura;
  
  switch(leitura) /*  antes tinha *jogatual*/
  {
    case KEY_RIGHT:
      if(g.lab[pacx + 1][pacy]!= '#')
      {
        g.pacman.pos.x++;
        //*joganterior=*jogatual;
      }
      break;    
    case KEY_LEFT:
      if(g.lab[pacx - 1][pacy]!= '#')
      {
        g.pacman.pos.x++;
       // *joganterior=*jogatual;
      }
      break;    
    case KEY_UP:
      if(g.lab[pacx][pacy -  1]!= '#')
      {
        g.pacman.pos.y--;
       // *joganterior=*jogatual;
      }
      break;    
    case KEY_DOWN:
      if(g.lab[pacx][pacy + 1]!= '#')
      {
        g.pacman.pos.y++;
       // *joganterior=*jogatual;
      }
      break;    
  }
  if(*joganterior!=*jogatual)
  {
    switch(*joganterior)
    {
      case KEY_RIGHT:
      if(g.lab[pacx+1][pacy]!= '#')
        g.pacman.pos.x++;
       break;
    }   
  }
  return g;
}    

void debugPacman(t_game jogo)
{
    mvprintw(5, 25, "pacman.x: %d", jogo.pacman.pos.x);
    mvprintw(6, 25, "pacman.y: %d", jogo.pacman.pos.y);
    mvprintw(7, 25, "fantasma[blinky].x: %d", jogo.ghost[blinky].pos.x);
    mvprintw(8, 25, "fantasma[blinky].y: %d", jogo.ghost[blinky].pos.y);
    mvprintw(9, 25, "fantasma[clyde].x: %d", jogo.ghost[clyde].pos.x);
    mvprintw(10, 25, "fantasma[clyde].y: %d", jogo.ghost[clyde].pos.y);
    mvprintw(11, 25, "fantasma[pinky].x: %d", jogo.ghost[pinky].pos.x);
    mvprintw(12, 25, "fantasma[pinky].y: %d", jogo.ghost[pinky].pos.y);
    mvprintw(13, 25, "fantasma[inky].x: %d", jogo.ghost[inky].pos.x);
    mvprintw(14, 25, "fantasma[inky].y: %d", jogo.ghost[inky].pos.y);
    mvprintw(15, 25, " score : %d", jogo.pacman.score);

    int paredePinky = isParede (jogo,
                                jogo.ghost[pinky].pos.x,
                                jogo.ghost[pinky].pos.y) ;
    
    mvprintw(3, 25, "isparede: %d", paredePinky ); 
   // iasaadd,

mvprintw(21,25 , "dir pinky : %d", jogo.ghost[pinky].dir );


}


/**
 * Funcao que vai fazer o pacman andar
 *
 */
t_game andapac(t_game jogo, int kin) 
{
  int  temParede=1;
  int xAtual= jogo.pacman.pos.x;
  int yAtual= jogo.pacman.pos.y;
  int proximoX=xAtual ,proximoY=yAtual;
  t_pos novaPosicao;
  int  novaDirecao;
  int ultimaDirecao=jogo.pacman.dir,preMove=0;
  switch(kin)
  {
      case KEY_RIGHT: 
          proximoX = xAtual+1;
          proximoY = yAtual;
          temParede = isParede (jogo , proximoX, proximoY);
            if(!temParede)
            {    
                jogo.pacman.dir = right;    
                ultimaDirecao = jogo.pacman.dir;    
                ultimaDirecao = right;    
                mvprintw(31,25 , "else: %d", xAtual ); //debug
                jogo.pacman.pos.x= jogo.pacman.pos.x +1;
                preMove = 0;
                jogo= pegaPellet(jogo,proximoX,proximoY);
            }
            else
            {
              ultimaDirecao = KEY_RIGHT;   
            }
                
      break;
      case KEY_LEFT: 
          proximoX = xAtual - 1;
          proximoY = yAtual;
          temParede = isParede (jogo , proximoX, proximoY);
            if(!temParede)
            {
              jogo.pacman.dir = left;    
              ultimaDirecao = jogo.pacman.dir;    
              mvprintw(31,25 , "else: %d", xAtual ); //debug
              jogo.pacman.pos.x= jogo.pacman.pos.x - 1;
              preMove = 0;
              jogo= pegaPellet(jogo,proximoX,proximoY);
            }
            else
            {
              ultimaDirecao = KEY_LEFT;   
            }
      break;
      case KEY_UP: 
          proximoX = xAtual ;
          proximoY = yAtual-1;
          temParede = isParede (jogo , proximoX, proximoY);
            if(!temParede)
            {
              jogo.pacman.dir = up;    
              ultimaDirecao = jogo.pacman.dir;    
              mvprintw(31,25 , "else: %d", xAtual ); //debug
              jogo.pacman.pos.y= jogo.pacman.pos.y - 1;
              jogo= pegaPellet(jogo,proximoX,proximoY);
                preMove = 0;
            }
            else
            {
              ultimaDirecao =KEY_UP;   
            }
      break;
      case KEY_DOWN: 
          proximoX = xAtual;
          proximoY = yAtual+1;
          temParede = isParede (jogo , proximoX, proximoY);
            if(!temParede)
            {
              jogo.pacman.dir = down;    
              ultimaDirecao = jogo.pacman.dir;    
              mvprintw(31,25 , "else: %d", xAtual ); //debug
              jogo.pacman.pos.y= jogo.pacman.pos.y  + 1;
              jogo= pegaPellet(jogo,proximoX,proximoY);
              preMove = 0;
            }
            else
            {
              ultimaDirecao = KEY_DOWN;   
            }

      break;
  
       default:
       {    
           switch(ultimaDirecao)
           {
                case left :
                proximoX = xAtual - 1;
                proximoY = yAtual;
                temParede = isParede (jogo , proximoX, proximoY);
                if(!temParede)
                {
                 // if(preMove!=0)
                 // {
               //      int z= andapac(t_game jogo, int preMove); 
                 // }    
                 // else 
                //  {   
                    jogo.pacman.dir = left;    
                    ultimaDirecao = jogo.pacman.dir;    
                    mvprintw(31,25 , "else: %d", xAtual ); //debug
                    jogo.pacman.pos.x= jogo.pacman.pos.x - 1;
                    jogo= pegaPellet(jogo,proximoX,proximoY);
                
                 // }
                }  
                break;
          
          case right :
              proximoX = xAtual + 1;
              proximoY = yAtual;
              temParede = isParede (jogo , proximoX, proximoY);
              if(!temParede)
              {
               //   if(preMove!=0)
                 // {
                 //    int z= andapac(t_game jogo, int preMove); 
                 // }    
                 // else 
                 // {   

                  jogo.pacman.dir = right;    
                  ultimaDirecao = jogo.pacman.dir;    
                  mvprintw(31,25 , "else: %d", xAtual ); //debug
                  jogo.pacman.pos.x= jogo.pacman.pos.x + 1;
                  jogo=pegaPellet(jogo,proximoX,proximoY);
              }  
          break;
          case up :
              proximoY = yAtual - 1;
              proximoX = xAtual;
              temParede = isParede (jogo , proximoX, proximoY);
              if(!temParede)
              {
               //   if(preMove!=0)
                 // {
                   //  int z= andapac(t_game jogo, int preMove); 
                 // }    
                 // else 
                  //{   
                  jogo.pacman.dir = up;    
                  ultimaDirecao = jogo.pacman.dir;    
                  mvprintw(31,25 , "else: %d", xAtual ); //debug
                  jogo.pacman.pos.y= jogo.pacman.pos.y - 1;
                  jogo= pegaPellet(jogo,proximoX,proximoY);
              }  
          break;
          case down :
              proximoY = yAtual + 1;
              proximoX= xAtual;
              temParede = isParede (jogo , proximoX, proximoY);
              if(!temParede)
              {
               //   if(preMove!=0)
                 // {
                   //  int z=  andapac(t_game jogo, int preMove); 
                 // }    
                 // else 
                 // {   
                  jogo.pacman.dir = down;    
                  ultimaDirecao = jogo.pacman.dir;    
                  mvprintw(31,25 , "else: %d", xAtual ); //debug
                  jogo.pacman.pos.y = jogo.pacman.pos.y +1;
                  jogo= pegaPellet(jogo,proximoX,proximoY);
              }  
          break;
        }
       }      
  }  
      return jogo;
}

int isParede(t_game jogo, int x, int y)
{  
  
  int parede = 0;
  
  if( jogo.lab[y][x] == '#'|| jogo.lab[y][x] == '-')
  {   
     parede = 1;
     mvprintw(1, 25, "verificando (%d ,%d) %c %d", x , y, jogo.lab[y][x], jogo.lab[y][x] == '#'  );
  } 

  return parede;

}
t_game pegaPellet(t_game jogo, int x, int y)
{
    if( jogo.lab[y][x] == '.')
    {    
        jogo.pacman.score= jogo.pacman.score + 50; /* 0 points */
        jogo.lab[y][x] = ' '; 
    }
    if( jogo.lab[y][x] == 'o')
    {    
        jogo.pacman.score= jogo.pacman.score + 50; /* 0 points */
        jogo.lab[y][x] = ' '; 
    }
     return jogo ;
}   
  /* ---------------------------------------------------------------------- */
  /* vi: set ai et ts=2 sw=2 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20150619.231433      */



