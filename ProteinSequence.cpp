//
// Created by Арина Суполярина on 17.10.2023.
//

#include "ProteinSequence.h"

ProteinSequence::ProteinSequence(
    const std::array<Nucleotide, 3>& nucleotides,
    const std::vector<AminoAcid>& amino_acid)
    : AminoAcid(nucleotides), amino_acids_(amino_acid) {
}

std::string ProteinSequence::Combine2() const {
  std::string result;

  result = this->Combine();

  for (const AminoAcid& amino_acid : amino_acids_) {
    result += amino_acid.Combine();
  }
  return result;
}

const std::vector<AminoAcid>& ProteinSequence::GetAminoAcids() const {
  return amino_acids_;
}

void ProteinSequence::SetAminoAcids(
    const std::vector<AminoAcid>& amino_acids) {
  amino_acids_ = amino_acids;
}
