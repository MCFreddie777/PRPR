cmake_minimum_required(VERSION 3.14)
project(Turing-Cvic9)

include_directories(common)

add_executable(01-film_fanusik src/01-film_fanusik/01-film_fanusik.c)
add_executable(02-vloz_zoznam src/02-vloz_zoznam/02-vloz_zoznam.c src/common/linked_list.h src/common/linked_list.c)
add_executable(03-zmaz_zoznam src/03-zmaz_zoznam/03-zmaz_zoznam.c src/common/linked_list.h src/common/linked_list.c)
add_executable(04-zmaz_delitelne src/04-zmaz_delitelne/04-zmaz_delitelne.c src/common/linked_list.h src/common/linked_list.c)
add_executable(05-otoc src/05-otoc/05-otoc.c src/common/linked_list.h src/common/linked_list.c)
add_executable(06-vypis_rekurz src/06-vypis_rekurz/06-vypis_rekurz.c src/common/linked_list.h src/common/linked_list.c)
add_executable(07-opacny_vypis_rekurz src/07-opacny_vypis_rekurz/07-opacny_vypis_rekurz.c src/common/linked_list.h src/common/linked_list.c)

