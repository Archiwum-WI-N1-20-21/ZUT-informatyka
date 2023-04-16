import numpy as np
import random
import matplotlib.pyplot as plt
import matplotlib.cm as cm

def checkFitness(pop):
    fit = np.zeros((pop[:,1].size,1))
    for index, solution in enumerate(pop):
        for ia,a in enumerate(solution, start = 1):
            for ib, b in enumerate(solution[ia:(len(solution))], start = ia+1):
                if abs(a-b) == abs(ia-ib):
                    fit[index,0] = fit[index,0] + 1
                    
    return fit

def fillGene(f,p):
    for _, a in enumerate(p):
        if a not in f:
            for ib, b in enumerate(f):
                if b == 0 :
                    f[ib] = a
                    break
                
    return f

def order_crossover(p1, p2, size):
    f1 = np.zeros(len(p1))
    f2 = np.zeros(len(p2))

    c = random.randint(0, (len(p1)-size))

    f1[c:c+size] = p1[c:c+size]
    f2[c:c+size] = p2[c:c+size]
 
    f1 = fillGene(f1,p2)
    f2 = fillGene(f2,p1)

    children = np.vstack([f1,f2])
    
    return children

def selection(pop, p_sel):
    sel_pool = np.random.permutation(pop[:,1].size)[0:int(round(pop[:,1].size*p_sel))]
    bestSol = pop[sel_pool[0],:]
    for sol in sel_pool[1:len(sel_pool)]:
        if pop[sol,len(bestSol)-1] < bestSol[len(bestSol)-1]:
            bestSol = pop[sol,:]

    return bestSol

def swap_mutation(child, numberOfSwaps):

    for i in range(numberOfSwaps):
        swapGenesPairs = np.random.choice(len(child), 2, replace = False)
        a = child[swapGenesPairs[0]]
        b = child[swapGenesPairs[1]]

        child[swapGenesPairs[0]] = b
        child[swapGenesPairs[1]] = a 

    return child

def checkerboard(shape):
    return np.indices(shape).sum(axis=0) % 2

SWAPS_CROSS = 2 # variables changed during order crossover 
NUMBER_OF_SWAPS = 2 # Number of swaps during mutation

POP = 100 # Population   
SIZE = 10 # Size of board
GENERATION = 1000 # Number of generations
SEL_PROB = 0.7 # Probability of crossing
MUT_PROB = 0.5 # Probability of mutation

if __name__ == "__main__":
	pop = np.zeros((POP,SIZE))
	for i in range(POP):
		pop[i,:] = np.random.permutation(SIZE)+1

	fit = checkFitness(pop)
	pop = np.hstack((pop, fit))

	meanFit = np.zeros(GENERATION)
	fitpergen = np.zeros(GENERATION)

	for gen in range(GENERATION):
		parents = [selection(pop,SEL_PROB),selection(pop,SEL_PROB)]
		children = order_crossover(parents[0][0:SIZE], parents[1][0:SIZE], SWAPS_CROSS)
		for child in range(len(children)):
			r_m = round(random.random(),2)
			if r_m <= MUT_PROB:
				children[child] = swap_mutation(children[child], NUMBER_OF_SWAPS) 
		fitOff = checkFitness(children)
		children = np.hstack((children, fitOff))
		pop = np.vstack([pop,children])
		pop = pop[pop[:,SIZE].argsort()][0:POP, :]
		meanFit[gen] = (pop[:,SIZE]).mean()
		fitpergen[gen] = fitOff.mean()

	bestSol = pop[np.argmin(pop[:, SIZE]), :]

	plt.plot(meanFit)
	plt.grid()
	plt.title("Evolution of Fit")
	plt.ylabel("Fit")
	plt.xlabel("Generation")
	plt.show()
	plt.title("Mean value of Fit in generation")
	plt.ylabel("Fit")
	plt.xlabel("Generation")
	plt.plot(fitpergen)
	plt.show()

	print(f"Solution have: {bestSol[SIZE]} conflicts")
	print(bestSol[0:SIZE])