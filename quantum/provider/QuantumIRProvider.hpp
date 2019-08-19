#ifndef QUANTUM_IRPROVIDER_HPP_
#define QUANTUM_IRPROVIDER_HPP_

#include "Identifiable.hpp"

#include "IRProvider.hpp"

namespace xacc {
namespace quantum {

class QuantumIRProvider : public IRProvider {

public:
  QuantumIRProvider() = default;

  const int getNRequiredBits(const std::string name) override;
  std::shared_ptr<Instruction> createInstruction(const std::string name,
                                                         std::size_t bit) override;
  std::shared_ptr<Instruction>
  createInstruction(const std::string name, std::vector<std::size_t> bits,
                    std::vector<InstructionParameter> parameters =
                        std::vector<InstructionParameter>{}) override;

  std::shared_ptr<CompositeInstruction>
  createComposite(const std::string name,
                  std::vector<std::string> variables = {}) override;

  std::shared_ptr<IR> createIR() override;

  std::vector<std::string> getInstructions() override;

  const std::string name() const override { return "quantum"; }
  const std::string description() const override {
    return "This IRProvider implementation "
           "generates and returns gate and annealing instructions.";
  }
};

} // namespace quantum
} // namespace xacc

#endif