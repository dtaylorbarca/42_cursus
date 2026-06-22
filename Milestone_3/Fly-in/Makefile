PYTHON     := python3
PIP        := pip
SRC_DIR    := .
MAIN_SCRIPT:= flyin.py

ARGS       ?= $(filter-out $@,$(MAKECMDGOALS))

.PHONY: install run debug clean lint lint-strict

all: install

install:
	@echo "Installing project dependencies..."
	$(PIP) install -r requirements.txt

run:
	@echo "Running simulation with arguments: $(ARGS)"
	$(PYTHON) $(MAIN_SCRIPT) $(ARGS)

debug:
	@echo "Debugging simulation with arguments: $(ARGS)"
	$(PYTHON) -m pdb $(MAIN_SCRIPT) $(ARGS)

clean:
	@echo "Cleaning up caches and temporary files..."
	rm -rf __pycache__ .pytest_cache .mypy_cache
	find . -type d -name "__pycache__" -exec rm -rf {} +
	find . -type f -name "*.pyc" -delete

lint:
	@echo "Running flake8 linting..."
	flake8 $(SRC_DIR)
	@echo "Running mypy static type checking..."
	mypy --warn-return-any --warn-unused-ignores --ignore-missing-imports --disallow-untyped-defs --check-untyped-defs $(SRC_DIR)

lint-strict:
	@echo "Running strict quality checks..."
	flake8 $(SRC_DIR)
	mypy --strict $(SRC_DIR)

%:
	@:
