from queue import Queue
from timeit import default_timer as timer
import matplotlib.pyplot as plt
import numpy as np

def notAttacking(board):
	for i in range(1, len(board)):
		for j in range(0, i):
			if board[i] == board[j] or abs(board[i] - board[j]) == abs(j - i):
				return True
	return False

if __name__ == "__main__":
	size_min = int(input("Min size of board to time: "))
	if size_min < 4:
		print("Min size of the board must be >= 4\nExiting...")
		exit(1)
	size_max = int(input("Max size of board to time: "))
	if size_max < size_min:
		print("Max size of the board must be >= min size\nExiting...")
		exit(1)
	print_solutions = input("Print solutions at the end? (y/n): ").lower()
	debug_mode = input("Print all boards as they generate? (y/n) (times will be false): ").lower()
	print()

	stat_arr_boards_generated = []
	stat_arr_boards_checked = []
	stat_arr_time = []

	for size in range(size_min, size_max + 1):
		boards_generated = 0
		boards_checked = 0
		start = None
		start = timer()
		solutions = []
		queue = Queue()
		queue.put([])
		while not queue.empty():
			board = queue.get()
			if debug_mode == 'y': print(board)
			length = len(board)
			if length == size:
				if not notAttacking(board):
					boards_checked += 1
					solutions.append(board)
				continue
			for col in range(size):
				queen = col
				queens = board.copy()
				queens.append(queen)
				queue.put(queens)
				boards_generated += 1
		end = timer()

		print("Size: {} / Time: {}s / Found {} solutions".format(size, end - start, len(solutions)))
		print("Boards generated: {} / Boards checked: {}".format(boards_generated, boards_checked))
		if print_solutions == 'y': print("Solutions: ", solutions, "\n")

		stat_arr_boards_generated.append(boards_generated)
		stat_arr_boards_checked.append(boards_checked)
		stat_arr_time.append(end - start)


	fig, axs = plt.subplots(2)
	for size in range(size_min, size_max + 1):
		axs[0].plot(np.linspace(0, stat_arr_time[size - size_min], 1000), label = "Size: {}".format(size))
		axs[1].plot(np.linspace(0, stat_arr_boards_checked[size - size_min], 1000), (np.linspace(0, stat_arr_boards_generated[size - size_min], 1000)), label = "Size: {}".format(size))

	axs[0].set_title("Time to find all solutions")
	axs[0].legend()
	axs[1].set_title("Boards checked to boards generated")
	axs[1].legend()
	plt.show()