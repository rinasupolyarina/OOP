//
// Created by Арина Суполярина on 17.10.2023.
//

#ifndef PROTEIN_PROTEINSEQUENETEST_H_
#define PROTEIN_PROTEINSEQUENETEST_H_

#include "AminoAcid.h"
#include <vector>
#include <string>

class ProteinSequence : public AminoAcid {
 public:
  ProteinSequence() = default;

  ~ProteinSequence() = default;

  ProteinSequence(const ProteinSequence& other) = default;

  ProteinSequence(const std::array<Nucleotide, 3>& nucleotides,
                  const std::vector<AminoAcid>& amino_acids);

  std::string Combine2() const;

  const std::vector<AminoAcid>& GetAminoAcids() const;

  void SetAminoAcids(const std::vector<AminoAcid>& amino_acids);

 private:
  std::vector<AminoAcid> amino_acids_;
};

#endif //PROTEIN_CMAKE_BUILD_DEBUG_PROTEINSEQUENETEST_H_
