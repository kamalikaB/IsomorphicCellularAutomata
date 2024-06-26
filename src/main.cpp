// కర్మణ్యే వాధికారస్తే మా ఫలేషు కదాచన |
// మా కర్మ ఫలహేతుర్భూర్మాతే సంగోస్త్వ కర్మణీ ||

// మయి సర్వాణి కర్మాణి సంన్యస్యాధ్యాత్మచేతసా |
// నిరాశీర్నిర్మమో భూత్వా యుధ్యస్వ విగతజ్వరః ||

#include <iostream>

#include "models/binary-1d-ca-manager/binary-1d-ca-manager.hpp"
#include "types/types.hpp"
#include "utils/utils.hpp"

class controller
{
  private:
    models::binary_1d_ca_manager ca_manager{};

  public:
    void
    run()
    {
      bool run_system{true};

      static std::vector<std::string> choices{
        "Print complementable reversible linear ECAs",
        "Print linear ECAs with non-trivial reversed pseudo-isomorphisms",
        "Print random ECAs with non-trivial reversed pseudo-isomorphisms",
        "Print random single cycle reversible ECAs",
        "Print random reversible ECAs",
        "Feed CA details manually",
        "Exit"
      };

      while (run_system)
      {
        try
        {
          types::short_whole_num choice{utils::general::get_choice(choices)};

          switch (choice)
          {
            case 1:
              models::rule_vector::print_complementable_rule_vectors();
              break;

            case 2:
              models::binary_1d_ca_manager::print_reversed_pseudo_isomorphable_ecas(true);
              break;

            case 3:
              models::binary_1d_ca_manager::print_reversed_pseudo_isomorphable_ecas();
              break;

            case 4:
              models::binary_1d_ca_manager::print_single_cycle_reversible_ecas();
              break;

            case 5:
              this->ca_manager.print_reversible_ecas();
              break;

            case 6:
              this->ca_manager.access_system();
              break;

            default:
              run_system = false;
              std::cout << "\n";
          }
        }
        catch (const std::exception &err)
        {
          utils::general::print_msg(err.what(), colors::red);
        }
      }
    }
};

int
main()
{
  utils::general::initialize();
  controller{}.run();
  return 0;
}
