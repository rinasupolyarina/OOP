//
// Created by Арина Суполярина on 19.10.2023.
//

#include "AminoAcid.h"
#include "Nucleotide.h"

AminoAcid::AminoAcid(const std::array<Nucleotide, 3>& nucleotide_array)
    : nucleotide_array_(nucleotide_array) {}

AminoAcid::AminoAcid(const std::string& sequence)
    : nucleotide_array_() {
  int count = 0;
  for (char el : sequence) {
    if (el == 'A' || el == 'C' || el == 'G' || el == 'T' || el == 'U') {
      nucleotide_array_[count] = el;
      count++;
      if (count == 3) {
        break;
      }
    }
  }
}

std::string AminoAcid::Combine() const {
  std::string combined;
  for (const Nucleotide& el : nucleotide_array_) {
    combined += el.GetNucleotide();
  }
  return combined;
}

const std::array<Nucleotide, 3>& AminoAcid::GetNucleotides() const {
  return nucleotide_array_;
}

void AminoAcid::SetNucleotides(
    const std::array<Nucleotide, 3>& nucleotide_array) {
  nucleotide_array_ = nucleotide_array;
}
