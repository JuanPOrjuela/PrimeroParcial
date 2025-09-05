import time
import time as t
import tracemalloc
import gc

students = [
    {"name": "ana",     "grade": 85},
    {"name": "carlos",  "grade": 92},
    {"name": "beatriz", "grade": 85},
    {"name": "diana",   "grade": 92},
    {"name": "alan",    "grade": 70},
    {"name": "beto",    "grade": 85},
]

def is_better(a, b):
    if a["grade"] > b["grade"]:
        return True
    if a["grade"] < b["grade"]:
        return False
    return a["name"] < b["name"]

def selection_sort_inplace(lst):
    n = len(lst)
    for i in range(n - 1):
        best_idx = i
        j = i + 1
        while j < n:
            if is_better(lst[j], lst[best_idx]):
                best_idx = j
            j += 1
        if best_idx != i:
            lst[i], lst[best_idx] = lst[best_idx], lst[i]

def human_bytes(n):
    if n < 1024:
        return f"{n} B"
    if n < 1024**2:
        return f"{n/1024:.2f} KB"
    return f"{n/1024**2:.2f} MB"

def main():
    xs = students  

    tracemalloc.start()
    gc.collect()  
    start_wall = time.perf_counter()
    start_cpu = time.process_time()

    selection_sort_inplace(xs)

    gc.collect()
    current, peak = tracemalloc.get_traced_memory()
    tracemalloc.stop()

    end_cpu = time.process_time()
    end_wall = time.perf_counter()

    print("Ordenando estudiantes (nota descendente, nombre ascendente en empate):")
    for s in xs:
        print(f"{s['name']} - {s['grade']}")

    wall_sec = end_wall - start_wall
    cpu_sec = end_cpu - start_cpu

    print()
    print(f"wall time: {wall_sec:.6f} s")
    print(f"cpu  time: {cpu_sec:.6f} s")
    print(f"mem current: {human_bytes(current)}")
    print(f"mem peak   : {human_bytes(peak)}")

if __name__ == "__main__":
    main()
