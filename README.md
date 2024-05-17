# FFMPEG_Project
Проект собирается Cmake в среде Linux.

Программа выводит информацию о видеофайле:
1. Количество потоков
2. Тип видеокодека
3. Количество кадров
4. Тип аудиокодека
5. Длительность видео в секундах

Инструкция по сборке и использованию:
1. Скопировать репозиторий на локальную машину, указав команду: git clone https://github.com/Sergey-Sitnikov/FFMPEG_Project.git
2. Перейти в корневую папку программы и выполнить следующие команды:
    mkdir build
    cd build
    cmake ..
    make

Для запуска программы нужно в командной строке указать путь к полученому файлу "video_info" и через пробел путь к видеофайлу.
