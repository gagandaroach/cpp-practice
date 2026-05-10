# List of subdirectories with programs
SUBDIRS = ascii-art days-since loan-calculator minesweeper multiplication-table word-freq

.PHONY: all build clean run-% $(SUBDIRS)

# Default target
all: build

# Build all programs
build: $(SUBDIRS)

# Individual program targets
ascii-art:
	@echo "Building ascii-art..."
	cd ascii-art && g++ -std=c++11 -Wall -Wextra main.cpp -o ascii-art.out

days-since:
	@echo "Building days-since..."
	cd days-since && g++ -std=c++11 -Wall -Wextra main.cpp -o days-since.out

loan-calculator:
	@echo "Building loan-calculator..."
	cd loan-calculator && g++ -std=c++11 -Wall -Wextra main.cpp -o loan_calculator.out

minesweeper:
	@echo "Building minesweeper..."
	cd minesweeper && g++ -std=c++11 -Wall -Wextra main.cpp -o minesweeper.out

multiplication-table:
	@echo "Building multiplication-table..."
	cd multiplication-table && g++ -std=c++11 -Wall -Wextra main.cpp -o mult.out

word-freq:
	@echo "Building word-freq..."
	cd word-freq && g++ -std=c++11 -Wall -Wextra main.cpp -o wordfreq.out

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -f ascii-art/ascii-art.out
	rm -f days-since/days-since.out
	rm -f loan-calculator/loan_calculator.out
	rm -f minesweeper/minesweeper.out
	rm -f multiplication-table/mult.out
	rm -f word-freq/wordfreq.out

# Run targets (optional)
run-ascii-art: ascii-art
	@echo "Running ascii-art..."
	cd ascii-art && ./ascii-art.out

run-days-since: days-since
	@echo "Running days-since..."
	cd days-since && ./days-since.out

run-loan-calculator: loan-calculator
	@echo "Running loan-calculator..."
	cd loan-calculator && ./loan_calculator.out

run-minesweeper: minesweeper
	@echo "Running minesweeper..."
	cd minesweeper && ./minesweeper.out

run-multiplication-table: multiplication-table
	@echo "Running multiplication-table..."
	cd multiplication-table && ./mult.out

run-word-freq: word-freq
	@echo "Running word-freq..."
	cd word-freq && ./wordfreq.out

# Help
help:
	@echo "Available targets:"
	@echo "  all          - Build all programs (default)"
	@echo "  build        - Build all programs"
	@echo "  clean        - Remove all executables"
	@echo "  run-<name>   - Build and run a specific program"
	@echo "                 (e.g., run-ascii-art, run-days-since)"
	@echo "  help         - Show this help"