import numpy as np
import matplotlib.pyplot as plt



datosexp = np.loadtxt("RadialVelocities.dat")
datosnuevos = np.loadtxt("Rotacion.txt")


plt.plot(datosexp[1:,0],datosexp[1:,1])
plt.plot(datosnuevos[:,0],datosnuevos[:,1])
plt.title("Velocidad Circular de una galaxia")
plt.xlabel ("Radio")
plt.ylabel ("Velocidad")

plt.savefig("Solucion.png")