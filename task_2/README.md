# Задание 2.1. LED fuzzy traffic light
## Описание. Соберите цепь из трех LED на Arduino. Реализуйте управление состоянием LED через ROS узел на компьютере. Изначально все LED находятся в выключенном состоянии (не горят).

Вам необходимо:
1. Настроить последовательную связь между Arduino и компьютером (5).
2. Выбрать ROS сообщение и название топика для передачи команд Arduino.
Так как команды представляют из себя символы, целесообразно
использовать наиболее подходящий тип ROS сообщения (влияет на баллы).
3. Написать ROS узел для ожидания команд пользователя с клавиатуры и
отправки по последовательному соединению (через ROS топики!).
ROS узел может быть реализован на Python или C++ (10).
4. Собрать схему из трех LED (Red, Green и Blue) на Arduino.
5. Написать скетч на Arduino по переключению состояния LED в зависимости
от команды пользователя (10).
Команды пользователя:
• ‘R’, ‘G’ или ‘B’ – переключить состояние красного, зеленого или синего
LED (регистр не учитывается)
Предполагаемый сценарий. Пользователь последовательно нажимает на кнопки
клавиатуры ‘R’, ‘G’ и ‘B’ (в английской раскладке, регистр не важен). Все LED на
Arduino переключаются в состояние «включено». Пользователь нажимает на
кнопку клавиатуры G, зеленый LED переключается в состояние «выключено».

# Задание 2.2. LCD point WASD game
## Соберите цепь из LCD на Arduino. Реализуйте передвижение точки (пикселя) на LCD в зависимости от команды ROS узла на компьютере. Изначально точка на LCD находится по середине (по горизонту и вертикали).

Вам необходимо:
1. Настроить последовательную связь между Arduino и компьютером (5).
2. Выбрать ROS сообщение и название топика для передачи команд Arduino.
Так как команды представляют из себя символы, целесообразно
использовать наиболее подходящий тип ROS сообщения (влияет на баллы).
3. Написать ROS узел для ожидания команд пользователя с клавиатуры и
отправки по последовательному соединению (через ROS топики!).
ROS узел может быть реализован на Python или C++ (10).
4. Собрать схему из LCD на Arduino.
5. Написать скетч на Arduino по перемещению точки (пикселя) на LCD в
зависимости от команды пользователя (10).
Команды пользователя:
• ‘W’, ‘A’, ‘S’, ‘D’ – вверх, влево, вниз, вправо (регистр не учитывается)
Предполагаемый сценарий. Пользователь последовательно нажимает на кнопки
клавиатуры ‘W’, ‘A’, ‘S’ и ‘D’ (в английской раскладке, регистр не важен). Точка
на LCD последовательно передвигается вверх, влево, вниз и вправо, возвращаясь
на середину экрана.

# Задание 2.3. Sensor Logger
## ССоберите цепь из не менее двух датчиков на Arduino (температура, влажность, давление и пр.). Реализуйте логирование и отображение данных в реальном времени на компьютере.

Вам необходимо:
1. Настроить последовательную связь между Arduino и компьютером (5).
2. Выбрать ROS сообщения и названия топиков для передачи данных с
сенсоров Arduino. Так как данные представляют из себя скалярные величины,
целесообразно использовать наиболее подходящий тип ROS сообщения
(влияет на баллы).
3. Написать ROS узел для логирования данных со всех сенсоров (топиков) при
помощи ROS Bag. ROS узел может быть реализован на Python или C++ (10).
4. Собрать схему с двумя и более сенсорами на Arduino.
5. Написать скетч на Arduino для передачи данных сенсоров по
последовательному соединению на компьютер (10).
6. Отобразить данные сенсоров в реальном времени при помощи rqt_plot (5).
Важно! Некоторые датчики требуют калибровки.