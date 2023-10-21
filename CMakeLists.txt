cmake_minimum_required(VERSION 3.26)
project(Protein)

set(CMAKE_CXX_STANDARD 17)

add_executable(Protein
        main.cpp
        Nucleotide.h
        Nucleotide.cpp
        ProteinSequence.cpp
        ProteinSequence.h
        AminoAcid.cpp
        AminoAcid.h
)
