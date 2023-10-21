//
// Created by Арина Суполярина on 19.10.2023.
//

#ifndef PROTEIN__AMINOACID_H_
#define PROTEIN__AMINOACID_H_

#include <array>
#include <string>
#include "Nucleotide.h"

class AminoAcid {
 public:
  AminoAcid() = default;

  AminoAcid(const AminoAcid& other) = default;

  AminoAcid(const std::array<Nucleotide, 3>& nucleotide_array);

  AminoAcid(const std::string& sequence);

  ~AminoAcid() = default;

  std::string Combine() const;

  const std::array<Nucleotide, 3>& GetNucleotides() const;

  void SetNucleotides(const std::array<Nucleotide, 3>& nucleotide_array);


 private:
  std::array<Nucleotide, 3> nucleotide_array_;
};

#endif //PROTEIN__AMINOACID_H_
