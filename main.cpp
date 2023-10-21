// Вариант 5 
// Сотрудники института биоинформатики хотят восстановить первичную структуру 
// белка, для чего требуется объединить его (частично пересекающиеся) фрагменты. 
// Требуется написать программу, которая хранит белковые последовательности 
//  (в виде списков аминокислот) и умеет их объединять, если аминокислоты в 
//  конце одной последовательности совпадут с аминокислотами в начале другой. 

//  1) Класс трансляции протеиногенной аминокислоты, умеющий синтезировать ее 
//     по хранимому коду из последовательно поступающих нуклеотидов, 
//     закодированных при помощи однобуквенных обозначений. 

#include <iostream>
#include <cassert>

#include "ProteinSequence.h"
#include "Nucleotide.h"
#include "AminoAcid.h"

int main() {
  std::cout << "Laboratory work 1\n";

  std::cout << "\nStarting Nucleotide tests\n";

  {
    auto nucleotide1 = Nucleotide('A');
    assert(nucleotide1.GetNucleotide() == 'A');

    auto nucleotide2 = nucleotide1;
    assert(nucleotide2.GetNucleotide() == 'A');

    Nucleotide nucleotide3;
    assert(nucleotide3.GetNucleotide() == 'A');

    std::cout << "Nucleotide: test constructor passed\n";
  }

  {
    auto nucleotide = Nucleotide('A');
    assert(nucleotide.GetNucleotide() == 'A');
    std::cout << "Nucleotide: test getter passed\n";
  }

  {
    auto nucleotide = Nucleotide('A');
    assert(nucleotide.GetNucleotide() == 'A' && "test getter");

    nucleotide.SetNucleotide('U');
    assert(nucleotide.GetNucleotide() == 'U' && "test setter");
    std::cout << "Nucleotide: test setter passed\n";
  }

  std::cout << "\nStarting AminoAcid tests\n";

  {
    auto amino_acid1 = AminoAcid("AGDCDGDADDGKU");
    std::array<Nucleotide, 3> data = {
        Nucleotide('A'),
        Nucleotide('G'),
        Nucleotide('C')
    };
    assert(amino_acid1.GetNucleotides() == data);

    auto amino_acid2 = amino_acid1;
    assert(amino_acid2.GetNucleotides() == data);

    AminoAcid amino_acid3(data);
    assert(amino_acid3.GetNucleotides() == data);

    std::array<Nucleotide, 3> default_data = {
        Nucleotide('A'),
        Nucleotide('A'),
        Nucleotide('A')
    };
    AminoAcid amino_acid4;
    assert(amino_acid4.GetNucleotides() == default_data);

    std::cout << "AminoAcid: test constructor passed\n";
  }

  {
    std::array<Nucleotide, 3> data = {
        Nucleotide('A'),
        Nucleotide('G'),
        Nucleotide('C')
    };
    AminoAcid amino_acid(data);
    assert(amino_acid.GetNucleotides() == data);

    std::cout << "AminoAcid: test basic getter passed\n";
  }

  {
    AminoAcid amino_acid = AminoAcid("ACC");

    auto amino_acid_result = amino_acid.GetNucleotides();
    assert(amino_acid_result[0] == Nucleotide('A'));
    assert(amino_acid_result[1] == Nucleotide('C'));
    assert(amino_acid_result[2] == Nucleotide('C'));

    std::cout << "AminoAcid: test advanced getter passed\n";
  }

  {
    AminoAcid amino_acid = AminoAcid("AGDCDGDADDGKU");
    assert(amino_acid.Combine() == "AGC");
    std::cout << "AminoAcid: test Combine passed\n";
  }

  {
    auto amino_acid = AminoAcid("AGLSDCDGDADDGKU");

    assert(amino_acid.GetNucleotides()[0] == Nucleotide('A'));
    assert(amino_acid.GetNucleotides()[1] == Nucleotide('G'));
    assert(amino_acid.GetNucleotides()[2] == Nucleotide('C'));

    amino_acid.SetNucleotides({
                                  Nucleotide('A'),
                                  Nucleotide('C'),
                                  Nucleotide('C')
                              });
    assert(amino_acid.GetNucleotides()[0] == Nucleotide('A'));
    assert(amino_acid.GetNucleotides()[1] == Nucleotide('C'));
    assert(amino_acid.GetNucleotides()[2] == Nucleotide('C'));

    std::cout << "AminoAcid: test setter passed\n";
  }

  std::cout << "\n Starting ProteinSequence tests\n";

  {
    auto protein_sequence1 =
        ProteinSequence({
                                Nucleotide('G'),
                                Nucleotide('G'),
                                Nucleotide('U')
                            },
                        {
                            AminoAcid("ACC"),
                            AminoAcid("GUU")
                            }
    );

    auto amino_acids = protein_sequence1.GetAminoAcids();

    assert(amino_acids[0].GetNucleotides()[0] == Nucleotide('A'));
    assert(amino_acids[0].GetNucleotides()[1] == Nucleotide('C'));
    assert(amino_acids[0].GetNucleotides()[2] == Nucleotide('C'));
    assert(amino_acids[1].GetNucleotides()[0] == Nucleotide('G'));
    assert(amino_acids[1].GetNucleotides()[1] == Nucleotide('U'));
    assert(amino_acids[1].GetNucleotides()[2] == Nucleotide('U'));

    auto protein_sequence2 = protein_sequence1;

    auto amino_acids2 = protein_sequence2.GetAminoAcids();

    assert(amino_acids2[0].GetNucleotides()[0] == Nucleotide('A'));
    assert(amino_acids2[0].GetNucleotides()[1] == Nucleotide('C'));
    assert(amino_acids2[0].GetNucleotides()[2] == Nucleotide('C'));
    assert(amino_acids2[1].GetNucleotides()[0] == Nucleotide('G'));
    assert(amino_acids2[1].GetNucleotides()[1] == Nucleotide('U'));
    assert(amino_acids2[1].GetNucleotides()[2] == Nucleotide('U'));

    ProteinSequence protein_sequence3;
    assert(protein_sequence3.GetAminoAcids().size() == 0);


    std::cout << "ProteinSequence: test constructor passed\n";
  }

  {
    ProteinSequence protein_sequence =
        ProteinSequence({
                                Nucleotide('G'),
                                Nucleotide('G'),
                                Nucleotide('U')
                            },
                        {
                            AminoAcid("ACC"),
                            AminoAcid("GUU")
                            });

    std::vector<AminoAcid> amino_acids = protein_sequence.GetAminoAcids();

    assert(amino_acids[0].GetNucleotides()[0] == Nucleotide('A'));
    assert(amino_acids[0].GetNucleotides()[1] == Nucleotide('C'));
    assert(amino_acids[0].GetNucleotides()[2] == Nucleotide('C'));
    assert(amino_acids[1].GetNucleotides()[0] == Nucleotide('G'));
    assert(amino_acids[1].GetNucleotides()[1] == Nucleotide('U'));
    assert(amino_acids[1].GetNucleotides()[2] == Nucleotide('U'));

    std::cout << "ProteinSequence: test getter passed\n";
  }

  {
    ProteinSequence protein_sequence =
        ProteinSequence({
                                Nucleotide('G'),
                                Nucleotide('G'),
                                Nucleotide('U')
                            },
                        {
                            AminoAcid("ACC"),
                            AminoAcid("GUU")
                            }
        );
    assert(protein_sequence.Combine2() == "GGUACCGUU");
    std::cout << "ProteinSequence: test Combine2 passed\n";
  }

  {
    ProteinSequence protein_sequence =
        ProteinSequence({
                                Nucleotide('G'),
                                Nucleotide('G'),
                                Nucleotide('U')
                            },
                        {
                            AminoAcid("ACC"),
                            AminoAcid("GUU")
                            }
        );
    auto amino_acids = protein_sequence.GetAminoAcids();
    assert(amino_acids[0].GetNucleotides()[0] == Nucleotide('A'));
    assert(amino_acids[0].GetNucleotides()[1] == Nucleotide('C'));
    assert(amino_acids[0].GetNucleotides()[2] == Nucleotide('C'));
    assert(amino_acids[1].GetNucleotides()[0] == Nucleotide('G'));
    assert(amino_acids[1].GetNucleotides()[1] == Nucleotide('U'));
    assert(amino_acids[1].GetNucleotides()[2] == Nucleotide('U'));

    protein_sequence.SetAminoAcids({
                                       AminoAcid("GGU"),
                                       AminoAcid("ACC")
                                   });

    amino_acids = protein_sequence.GetAminoAcids();
    assert(amino_acids[0].GetNucleotides()[0] == Nucleotide('G'));
    assert(amino_acids[0].GetNucleotides()[1] == Nucleotide('G'));
    assert(amino_acids[0].GetNucleotides()[2] == Nucleotide('U'));
    assert(amino_acids[1].GetNucleotides()[0] == Nucleotide('A'));
    assert(amino_acids[1].GetNucleotides()[1] == Nucleotide('C'));
    assert(amino_acids[1].GetNucleotides()[2] == Nucleotide('C'));

    std::cout << "ProteinSequence: test setter passed\n";
  }

  std::cout << "All tests passed successfully\n";
}