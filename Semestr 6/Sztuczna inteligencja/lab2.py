from queue import Queue, LifoQueue
from timeit import default_timer as timer
import numpy as np
import matplotlib.pyplot as plt

def notAttacking(board):
	for i in range(1, len(board)):
		for j in range(0, i):
			if board[i] == board[j] or abs(board[i] - board[j]) == abs(j - i):
				return True
	return False

def BFS(debug_mode = 'n', print_solutions = 'n'):
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

		if print_solutions == 'y': print("BFS:\nSolutions: ", solutions, "\n")

		stat_arr_boards_generated_bfs.append(boards_generated)
		stat_arr_boards_checked_bfs.append(boards_checked)
		stat_arr_time_bfs.append(end - start)
		stat_arr_solutions_found_bfs.append(len(solutions))

def DFS(debug_mode = 'n', print_solutions = 'n'):
	for size in range(size_min, size_max + 1):
		boards_generated = 0
		boards_checked = 0
		start = None
		start = timer()
		solutions = []
		queue = LifoQueue()
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

		if print_solutions == 'y': print("DFS:\nSolutions: ", solutions, "\n")

		stat_arr_boards_generated_dfs.append(boards_generated)
		stat_arr_boards_checked_dfs.append(boards_checked)
		stat_arr_time_dfs.append(end - start)
		stat_arr_solutions_found_dfs.append(len(solutions))

def BFS_optimized(debug_mode = 'n', print_solutions = 'n'):
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
			if notAttacking(board):
				boards_checked += 1
				continue
			length = len(board)
			if length == size:
				solutions.append(board)
				continue
			for col in range(size):
				queen = col
				queens = board.copy()
				queens.append(queen)
				queue.put(queens)
				boards_generated += 1
		end = timer()

		if print_solutions == 'y': print("BFS optimized:\nSolutions: ", solutions, "\n")

		stat_arr_boards_generated_bfs_opt.append(boards_generated)
		stat_arr_boards_checked_bfs_opt.append(boards_checked)
		stat_arr_time_bfs_opt.append(end - start)
		stat_arr_solutions_found_bfs_opt.append(len(solutions))

def DFS_optimized(debug_mode = 'n', print_solutions = 'n'):
	for size in range(size_min, size_max + 1):
		boards_generated = 0
		boards_checked = 0
		start = None
		start = timer()
		solutions = []
		queue = LifoQueue()
		queue.put([])
		while not queue.empty():
			board = queue.get()
			if debug_mode == 'y': print(board)
			if notAttacking(board):
				boards_checked += 1
				continue
			length = len(board)
			if length == size:
				solutions.append(board)
				continue
			for col in range(size):
				queen = col
				queens = board.copy()
				queens.append(queen)
				queue.put(queens)
				boards_generated += 1
		end = timer()
		if print_solutions == 'y': print("DFS optimized:\nSolutions: ", solutions, "\n")

		stat_arr_boards_generated_dfs_opt.append(boards_generated)
		stat_arr_boards_checked_dfs_opt.append(boards_checked)
		stat_arr_time_dfs_opt.append(end - start)
		stat_arr_solutions_found_dfs_opt.append(len(solutions))

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

	stat_arr_boards_generated_bfs = []
	stat_arr_boards_checked_bfs = []
	stat_arr_time_bfs = []
	stat_arr_solutions_found_bfs = []
	stat_arr_boards_generated_bfs_opt = []
	stat_arr_boards_checked_bfs_opt = []
	stat_arr_time_bfs_opt = []
	stat_arr_solutions_found_bfs_opt = []
	stat_arr_boards_generated_dfs = []
	stat_arr_boards_checked_dfs = []
	stat_arr_time_dfs = []
	stat_arr_solutions_found_dfs = []
	stat_arr_boards_generated_dfs_opt = []
	stat_arr_boards_checked_dfs_opt = []
	stat_arr_time_dfs_opt = []
	stat_arr_solutions_found_dfs_opt = []

	BFS(debug_mode, print_solutions)
	BFS_optimized(debug_mode, print_solutions)
	DFS(debug_mode, print_solutions)
	DFS_optimized(debug_mode, print_solutions)

	for size in range(size_min, size_max + 1):
		print("\nSize: {}".format(size))
		print("BFS: \t\tSolutions: {} / Boards generated: {} / Boards checked: {} / Time: {}".format(stat_arr_solutions_found_bfs[size - size_min], stat_arr_boards_generated_bfs[size - size_min], stat_arr_boards_checked_bfs[size - size_min], stat_arr_time_bfs[size - size_min]))
		print("BFS optimized:  Solutions: {} / Boards generated: {} / Boards checked: {} / Time: {}".format(stat_arr_solutions_found_bfs_opt[size - size_min], stat_arr_boards_generated_bfs_opt[size - size_min], stat_arr_boards_checked_bfs_opt[size - size_min], stat_arr_time_bfs_opt[size - size_min]))
		print("DFS: \t\tSolutions: {} / Boards generated: {} / Boards checked: {} / Time: {}".format(stat_arr_solutions_found_dfs[size - size_min], stat_arr_boards_generated_dfs[size - size_min], stat_arr_boards_checked_dfs[size - size_min], stat_arr_time_dfs[size - size_min]))
		print("DFS optimized:  Solutions: {} / Boards generated: {} / Boards checked: {} / Time: {}".format(stat_arr_solutions_found_dfs_opt[size - size_min], stat_arr_boards_generated_dfs_opt[size - size_min], stat_arr_boards_checked_dfs_opt[size - size_min], stat_arr_time_dfs_opt[size - size_min]))

		fig, axs = plt.subplots(2)
		axs[0].bar(["BFS", "BFS optimized", "DFS", "DFS optimized"], [stat_arr_time_bfs[size - size_min], stat_arr_time_bfs_opt[size - size_min], stat_arr_time_dfs[size - size_min], stat_arr_time_dfs_opt[size - size_min]])
		axs[0].set_title("Time to find all solutions, size: {}".format(size))
		axs[1].plot(np.linspace(0, stat_arr_boards_checked_bfs[size - size_min], 1000), (np.linspace(0, stat_arr_boards_generated_bfs[size - size_min], 1000)), label = "BFS")
		axs[1].plot(np.linspace(0, stat_arr_boards_checked_bfs_opt[size - size_min], 1000), (np.linspace(0, stat_arr_boards_generated_bfs_opt[size - size_min], 1000)), label = "BFS optimized")
		axs[1].plot(np.linspace(0, stat_arr_boards_checked_dfs[size - size_min], 1000), np.linspace(0, stat_arr_boards_generated_dfs[size - size_min], 1000), label = "DFS")
		axs[1].plot(np.linspace(0, stat_arr_boards_checked_dfs_opt[size - size_min], 1000), np.linspace(0, stat_arr_boards_generated_dfs_opt[size - size_min], 1000), label = "DFS optimized")
		axs[1].set_title("Boards checked to boards generated, size: {}".format(size))
		axs[1].legend()
		plt.show()