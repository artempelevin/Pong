#ifndef SETTING_H
#define SETTING_H

#define SCREEN_WIDTH        600                             // Ширина экрана
#define SCREEN_HEIGHT       500                             // Высота экрана
#define SCREEN_CENTRE_X     SCREEN_WIDTH/2                  // Ширина экрана
#define SCREEN_CENTRE_Y     SCREEN_HEIGHT/2                 // Ширина экрана

#define UPDATE_RATE         1                               // Частота обновления (в миллисекундах)

#define BALL_SPEED          1                               // Скорость шара (в координатах)
#define BALL_SIZE           30                              // Размер шара
#define BALL_START_X        SCREEN_CENTRE_X -BALL_SIZE/2    // Стартовая координата X шара
#define BALL_START_Y        SCREEN_CENTRE_Y -BALL_SIZE/2    // Стартовая координата Y шара

#define RACKET_SPEED        1                               // Скорость ракетки (в координатах)
#define RACKET_WIDTH        30                              // Ширина ракетки
#define RACKET_HEIGHT       150                             // Высота ракетки

#define PLAYER_MOD          true                            // Левой ракеткой управляет игрок

#endif // SETTING_H
