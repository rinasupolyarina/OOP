//
// Created by Арина Суполярина on 23.09.2023.
//
#include "Nucleotide.h"

Nucleotide::Nucleotide(const Nucleotide& other) = default;

Nucleotide::Nucleotide(char nucleotide) :
    nucleotide_(nucleotide) {}

char Nucleotide::GetNucleotide() const { return nucleotide_; }

void Nucleotide::SetNucleotide(char nucleotide) {
  nucleotide_ = nucleotide;
}

bool Nucleotide::operator==(const Nucleotide& other) const {
  return nucleotide_ == other.nucleotide_;
}
