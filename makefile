#makefile
#by João Carlos Pinto
#date 2021-05-16

FXH = hash_known_algorithms.h
FXCOD = hash_teste_main.c hash_known_algorithms.c

hash_teste: $(FXCOD) $(FXH)
	gcc -o $@ $(FXCOD)
