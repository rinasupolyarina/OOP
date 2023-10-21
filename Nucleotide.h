//
// Created by Арина Суполярина on 23.09.2023.
//

#ifndef PROTEIN__NUCLEOTIDE_H_
#define PROTEIN__NUCLEOTIDE_H_

class Nucleotide {
 public:
  Nucleotide() = default;

  Nucleotide(char nucleotide);

  Nucleotide(const Nucleotide& other);

  ~Nucleotide() = default;

  char GetNucleotide() const;

  void SetNucleotide(char nucleotide);

  bool operator==(const Nucleotide& other) const;

 private:
  char nucleotide_ = 'A';
};
#endif //PROTEIN__NUCLEOTIDE_H_
