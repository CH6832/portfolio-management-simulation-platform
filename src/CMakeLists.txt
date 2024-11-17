# CMakeList.txt : CMake project for quantum-portfolio-optimizer, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (quantum-portfolio-optimizer "main.cpp"  "quantum_algorithms/QAOA.cpp" "quantum_algorithms/GroverSearch.cpp" "quantum_algorithms/VQE.cpp" "quantum_algorithms/QuantumAnnealing.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET quantum-portfolio-optimizer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
