
#include <ncurses.h>  // для корректного ввода
#include <stdio.h>
#include <stdlib.h>  // для константы
#include <time.h>  // для того чтобы задать зерно для рандома по времени
#include <unistd.h>  // для функции usleep()

#define HEIGHT 25
#define WIDTH 80
#define for_x for (int x = 0; x < w; x++)  // удобный макрос для фор
#define for_y for (int y = 0; y < h; y++)
#define for_xy for_x for_y  // макрос для двух фор

void show(void *u, int w, int h);
void evolve(void *u, int w, int h, int *change);
void game(int w, int h);

int main() {
    srand(time(NULL));          // задаём зерно для рандома
    int w = WIDTH, h = HEIGHT;  // ширина и высота
    game(w, h);                 // запускаем главную функцию
}

void show(void *u, int w, int h) {
    int(*univ)[w] = u;
    printf("\033[H");  // перевод на начало
    for_y {
        for_x printf(univ[y][x] ? "▀"
                                : "░");  // если в текущей клетке есть жизнь то рисуем квадратик иначе пробелы
        printf("\033[E");                // перевод на следующую строку
    }
    fflush(stdout);  // очищаем поток вывода
}

void evolve(void *u, int w, int h, int *change) {
    unsigned(*univ)[w] = u;
    unsigned new[h][w];  // инициализируем новый двумерный массив для новых значений жизни и смерти
    *change = 0;         // передаем в change что изменений нет

    for_y for_x {
        int n = 0;
        for (int y1 = y - 1; y1 <= y + 1; y1++)
            for (int x1 = x - 1; x1 <= x + 1; x1++)
                if (univ[(y1 + h) % h][(x1 + w) % w])
                    n++;  // если в соседней клеточке есть жизнь то прибавляем переменную

        if (univ[y][x])
            n--;  // если в текущей клеточке тоже есть жизнь но уменьшаем переменную отвечающую за количество
                  // жизней в соседней клеточке
        new[y][x] =
            (n == 3 || (n == 2 && univ[y][x]));  // если рядом 3 жизни или две жизни и мы тоже в клетке с
                                                 // жизнью то в новой итерации здесь тоже будет жизнь
    }
    for_y for_x {
        if (univ[y][x] != new[y][x]) {  // проверяем были ли изменения по сравнению со старым массивом
            *change = 1;
        }
        univ[y][x] = new[y][x];  // присваиваем оригинальному массиву новую итерацию эволюции
    }
}

void game(int w, int h) {
    unsigned univ[h][w];  // создаём главный двумерный массив для игры
    int life;             // временная переменная для записи в массив
    for_xy {
        if (scanf("%d", &life))  // записываем из потока ввода данные для массива
            univ[y][x] = life;  // присваиваем
        else {                  // рандомим если ввод некорректен
            for_xy univ[y][x] = rand() < RAND_MAX / 10 ? 1 : 0;
            break;
        }
    }
    int slp = 200000;  // переменная для задержки
    int change = 0;
    initscr();  // инициализация библиотеки ncurses для будущего ввода
    noecho();   // отключаем отображение вводимых символов
    while (1) {
        (void)freopen("/dev/tty", "r", stdin);  // путь к терминалу и перенаправления в него потока stdin
        show(univ, w, h);             // отображение всего
        evolve(univ, w, h, &change);  // шаг эволюции
        timeout(0);                   // ставим время для ввода 0
        char c = getch();             // берем значение из терминала
        switch (c) {  // если c 1 то увеличиваем ожидание, если 2 то уменьшаем
            case '1': {
                if (slp < 700000) slp += 15000;
                break;
            }
            case '2': {
                if (slp > 15000) slp -= 15000;
                break;
            }
            case 'q':
                endwin();  // выключение ncurses
                change = 0;
                break;
            default:
                usleep(slp);  // задержка
        }
        if (!change) return;  // если изменений за последний шаг не произошло то закрываем программу
    }
}
