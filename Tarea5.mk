all: Resultados_hw5.pdf Solucion.png Rotacion.txt CurvaRotacion.x

Resultados_hw5.pdf: Solucion.png
	pdflatex Resultados_hw5.tex

Solucion.png : Plots.py Rotacion.txt 
	python Plots.py

Rotacion.txt: CurvaRotacion.x
	tail -n +2 "RadialVelocities.dat" > "RadialVelocities1.dat"
	./CurvaRotacion.x

CurvaRotacion.x: CurvaRotacion.c
	gcc CurvaRotacion.c -lm -o CurvaRotacion.x

	

clean: 
	rm *.x *.png