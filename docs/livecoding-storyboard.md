---
icon: lucide/play-circle
---

# Livecoding Storyboard

This storyboard outlines the livecoding demonstrations aligned with the course schedule and exercises. Each segment corresponds to the lecture and lab sessions throughout the day.

## Session 1: Setup & Foundations (9:05–9:20)

### Objective
Guide learners through setting up the development environment and running their first Eigen program.

### Livecoding Flow

1. **Environment Setup Demo**
   - Clone the repository
   - Show CMake configuration
   - Build and run a minimal example
   - Compile `live_coding.cpp` in the build environment

2. **First Eigen Program**
   - Create a minimal matrix and vector
   - Display Hello World with matrices
   - Show compilation and execution

### Code Structure
```cpp
#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    Vector3d v(1, 2, 3);
    MatrixXd m = MatrixXd::Identity(3, 3);
    std::cout << "Vector:\n" << v << "\nMatrix:\n" << m << std::endl;
    return 0;
}
```

### Exercises Covered
- **Ex 1**: Vector Creation and Access
- **Ex 2**: Matrix Initialization

---

## Session 2: Matrices & Vectors Fundamentals (9:20–10:00)

### Objective
Teach core concepts of Eigen matrices and vectors with interactive demonstrations.

### Livecoding Flow

1. **Vector Operations**
   - Creation with different initialization methods
   - Accessing elements by index
   - Basic operations (resize, transpose)

2. **Matrix Operations**
   - Creating matrices (zeros, identity, random)
   - Row and column access
   - Matrix properties (size, shape)

3. **Basic Math Functions**
   - Element-wise operations
   - Aggregation methods (sum, mean, min, max)
   - Mathematical functions (abs, sqrt, exp)

### Key Concepts to Demonstrate
- Matrix storage order (row-major vs. column-major)
- Dynamic vs. fixed-size matrices
- `.array()` method for element-wise operations
- `cwiseAbs()`, `cwiseSqrt()`, `cwiseExp()` for element-wise math

### Code Snippets

**Vector Creation:**
```cpp
VectorXd v1(5);              // Uninitialized vector of size 5
VectorXd v2 = VectorXd::Zero(5);  // Vector of zeros
VectorXd v3 = VectorXd::Ones(5);  // Vector of ones
Vector3d v4(1, 2, 3);       // Fixed-size vector
```

**Element-wise Math:**
```cpp
VectorXd v(5);
v << 1, 2, 3, 4, 5;
auto result = v.array().sqrt();  // Element-wise square root
auto abs_v = v.array().abs();    // Element-wise absolute value
```

### Exercises Covered
- **Ex 1**: Vector Creation and Access
- **Ex 2**: Matrix Initialization
- **Ex 3**: Basic Math Functions (Part A)

---

## Lab Session 1: Guided Practice (10:20–11:00)

### Objective
Learners work through Exercises 1–3 with occasional instructor guidance.

### Instructor Role
- Walk through Exercise 1 with the group
- Demonstrate vector access patterns
- Show compilation errors and debugging tips
- Check on progress; assist with Exercise 2 if needed

### Common Issues to Address
- Indexing (0-based)
- Uninitialized vs. initialized vectors
- Compilation flags for optimization

### Live Debugging Moment
```cpp
// Common error: out-of-bounds access
VectorXd v(3);
std::cout << v(5) << std::endl;  // ERROR! Show the fix
```

---

## Session 3: Advanced Matrix Operations (11:00–12:00)

### Objective
Introduce matrix composition, decomposition, and advanced manipulations.

### Livecoding Flow

1. **Matrix Algebra**
   - Matrix addition, subtraction, multiplication
   - Dot product and matrix product
   - Element-wise vs. algebraic operations

2. **Block & Slicing Operations**
   - `.block()` method for submatrix extraction
   - `.row()`, `.col()` for accessing rows/columns
   - Block assignment

3. **Advanced Operations**
   - Matrix transpose, determinant, inverse
   - Singular value detection
   - `.fullPivLU()` for decomposition

4. **Special Matrix Structures**
   - Identity matrices
   - Diagonal matrices
   - Concatenation with `<<` operator

### Key Concepts to Demonstrate
- Difference between lazy evaluation and actual computation
- Block operations without copying
- Singular matrices and error handling

### Code Snippets

**Matrix Operations:**
```cpp
MatrixXd A = MatrixXd::Random(3, 3);
MatrixXd B = MatrixXd::Random(3, 3);
MatrixXd C = A * B;  // Matrix multiplication
auto det = A.determinant();
auto inv = A.inverse();
auto transposed = A.transpose();
```

**Block Operations:**
```cpp
MatrixXd M(4, 4);
M << 1, 2, 3, 4,
     5, 6, 7, 8,
     9, 10, 11, 12,
     13, 14, 15, 16;

auto topLeft = M.block(0, 0, 2, 2);     // 2x2 block
auto column2 = M.col(2);
M.row(0) = VectorXd::Ones(4);
```

**Concatenation:**
```cpp
MatrixXd A(2, 2), B(2, 2);
MatrixXd result(2, 4);
result << A, B;  // Horizontal concatenation
```

### Exercises Covered
- **Ex 4**: Coefficient-wise Operations
- **Ex 5**: Matrix Operations
- **Ex 6**: Vector-Matrix Operations
- **Ex 7**: Special Matrix Operations (partial)

---

## Lab Session 2: Intermediate Challenges (13:00–13:40)

### Objective
Learners tackle Exercises 4–7, focusing on matrix algebra and decompositions.

### Instructor Role
- Live demonstration of Exercise 5 (matrix operations)
- Show `.fullPivLu().isInvertible()` pattern for Exercise 7
- Debug common issues with matrix dimensions

### Common Pitfalls
- Matrix dimension mismatches
- Confusing element-wise vs. algebraic multiplication
- Numerical precision in equality checks

### Live Debugging Moment
```cpp
// Common error: dimension mismatch
MatrixXd A(3, 3), B(4, 4);
auto C = A * B;  // ERROR! Show correct dimensions
```

---

## Session 4: Best Practice & Integration (13:40–14:00)

### Objective
Introduce practical patterns, performance considerations, and debugging strategies.

### Livecoding Flow

1. **Performance Tips**
   - Fixed-size vs. dynamic matrices
   - Alignment and memory layout
   - `.noalias()` for assignment optimization

2. **Code Organization**
   - Function signatures with matrix parameters
   - Const-correctness
   - Documentation patterns

3. **Error Handling**
   - Checking matrix invertibility
   - Validating dimensions
   - Using assertions

### Code Snippets

**Performance Optimization:**
```cpp
// Without optimization
C = A * B * C;  // Two multiplications, temporary allocation

// With optimization
C.noalias() = A * B * C;  // Single evaluation
```

**Function Signatures:**
```cpp
double computeTrace(const MatrixXd& A) {
    return A.trace();
}

void transformInPlace(MatrixXd& A) {
    A *= 2.0;
}
```

---

## Lab Session 3: Advanced Techniques (14:20–15:00)

### Objective
Learners work through Exercises 8–12, exploring blocks, slicing, and reshaping.

### Instructor Role
- Walk through Exercise 8 (block operations) live
- Demonstrate `.reshaped()` for Exercise 10
- Show creative slicing with index vectors for Exercise 12

### Advanced Debugging
```cpp
// Exercise 12: Non-contiguous slicing
std::vector<int> indices = {0, 2, 4};
// Demonstrate pattern extraction
```

---

## Session 5: Parallel & Eigen (15:00–15:30)

### Objective
Introduce Eigen's built-in parallelization and OpenMP integration.

### Livecoding Flow

1. **Eigen with OpenMP**
   - Enabling parallelization at compile time
   - Understanding thread safety
   - Performance monitoring

2. **Large Matrix Operations**
   - When parallelization helps
   - Memory bandwidth limitations
   - Practical benchmarks

3. **Template Specialization**
   - Custom types with Eigen
   - SIMD optimizations
   - Compiler flags (`-march=native`, `-O3`)

### Code Snippets

**OpenMP Integration:**
```cpp
// Compile with: -fopenmp or -Qopenmp
#include <Eigen/Dense>
using namespace Eigen;

int main() {
    MatrixXd A(1000, 1000), B(1000, 1000);
    A.setRandom();
    B.setRandom();
    
    // Eigen automatically parallelizes with OpenMP
    #pragma omp parallel for
    for (int i = 0; i < 10; ++i) {
        MatrixXd C = A * B;
    }
    return 0;
}
```

### Connection to Course Content
- Leverage NAISS HPC environment
- Show ex16_omp.cpp as reference
- Discuss performance scaling

---

## Wrap-up & Q&A (15:30–15:40)

### Objective
Consolidate learning, address remaining questions, and provide next steps.

### Livecoding Activities
- Revisit one challenging example based on questions
- Show the online solutions resource
- Demonstrate how to explore Eigen documentation

### Next Steps
- Exercises 13–15 for self-study
- Linear system solving
- Image processing applications
- Contributing to the NAISS training materials

---

## Appendix: Key Eigen Patterns

### Common Operations Reference

```cpp
// Vector creation
VectorXd v = VectorXd::Zero(n);
VectorXd v = VectorXd::Ones(n);
VectorXd v = VectorXd::Random(n);
Vector3d v(1, 2, 3);

// Matrix creation
MatrixXd m = MatrixXd::Identity(n, n);
MatrixXd m = MatrixXd::Zero(n, m);
MatrixXd m(3, 3); m << 1, 2, 3, 4, 5, 6, 7, 8, 9;

// Element-wise operations
v.array() + 1.0;
v.array() * 2.0;
v.array().sqrt();
m.array().abs();

// Aggregations
v.sum(), v.mean(), v.minCoeff(), v.maxCoeff();

// Block operations
m.block(i, j, rows, cols);
m.row(i), m.col(j);
m.topLeftCorner(rows, cols);
m.bottomRightCorner(rows, cols);

// Linear algebra
m.transpose(), m.determinant(), m.inverse();
m.trace(), m.norm();

// Decompositions
FullPivLU<MatrixXd> lu(m);
lu.solve(b);
```

---

## Notes for Instructors

1. **Progress Tracking**: Adjust timing based on learner progress. The schedule provides buffers.
2. **Live Coding Best Practices**:
   - Type slowly and narrate your actions
   - Make intentional mistakes and debug them
   - Use compiler output to teach error messages
   - Ask learners to predict output before running

3. **Exercise Pacing**: 
   - If learners finish early, present advanced slicing techniques
   - If running late, focus on core concepts; save 13–15 for self-study

4. **Resources**:
   - Compiler Explorer template: https://godbolt.org/z/M6hfa3Eac
   - Eigen documentation: https://eigen.tuxfamily.org/
   - Course repository: https://github.com/NAISS-Training/array-computing
