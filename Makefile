hellomake: skipinstruction.c
	gcc -fno-stack-protector -z execstack -m64 -g skipinstruction.c -o skipinstruction
fun: fun.c
	gcc -fno-stack-protector -z execstack -m64 -g fun.c -o fun
chessAI: chessAI.c engine.c moverules.c
	gcc -fno-stack-protector -z execstack -m64 -g chessAI.c engine.c moverules.c -o chessAI

