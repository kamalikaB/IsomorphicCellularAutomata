#ifndef __BINARY_1D_CA__
#define __BINARY_1D_CA__

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "../../types/types.hpp"
#include "../binary-cell/binary-cell.hpp"
#include "../rule-vector/rule-vector.hpp"

namespace models
{
  class binary_1d_ca
  {
    private:
      types::short_whole_num num_cells{};
      types::short_whole_num num_neighbors{};
      types::short_whole_num num_configs{};
      types::short_whole_num l_radius{};
      types::short_whole_num r_radius{};

      std::vector<binary_cell> cells{};
      std::vector<types::sn_map> sn_maps{};

      types::boundary boundary{};
      types::transition_graph graph{};
      models::rule_vector rule_vector{};

      bool
      is_elementary() const;

      bool
      has_cycle_strucutre_as(const models::binary_1d_ca &other) const;

      bool
      has_complemented_isomorphisms() const;

      bool
      extract_rules(const types::transition_graph &graph, types::rules &rules) const;

      types::short_whole_num
      get_next_config(types::short_whole_num current_config);

      std::string
      get_neighborhood_str(types::short_whole_num cell_num, const std::string &config_str) const;

      std::unordered_set<types::short_whole_num>
      get_affected_configs(const models::binary_1d_ca &other, types::short_whole_num &num_cycles_affected) const;

      void
      set_rules(const types::rules &rules);

      void
      randomize_config();

      void
      fill_transition_graph();

      void
      fill_sn_maps();

    public:
      static const types::short_whole_num max_size{10};
      static const types::short_whole_num max_l_radius{2};
      static const types::short_whole_num max_r_radius{2};

      binary_1d_ca();

      binary_1d_ca(
        types::short_whole_num num_cells,
        types::short_whole_num l_radius,
        types::short_whole_num r_radius,
        types::boundary boundary,
        const types::rules &rules
      );

      types::short_whole_num
      get_num_cells() const;

      types::short_whole_num
      get_l_radius() const;

      types::short_whole_num
      get_r_radius() const;

      types::short_whole_num
      get_num_neighbors() const;

      types::short_whole_num
      get_num_configs() const;

      types::boundary
      get_boundary() const;

      const types::transition_graph &
      get_graph() const;

      const std::vector<types::sn_map> &
      get_sn_maps() const;

      const models::rule_vector &
      get_rule_vector() const;

      types::short_whole_num
      get_current_config() const;

      bool
      is_reversible() const;

      bool
      is_isomorphic(const models::binary_1d_ca &other) const;

      bool
      has_1_1_or_1_n_sn_maps() const;

      bool
      has_non_trivial_reversed_pseudo_isomorphisms(
        bool &has_trivial_partition,
        bool &has_non_trivial_partitions
      ) const;

      bool
      has_all_isomorphic_complements() const;

      void
      print_isomorphisms() const;

      void
      print_details() const;

      void
      print_transition_graph() const;

      void
      print_sn_maps() const;

      void
      print_complemented_isomorphisms() const;

      void
      print_reversed_pseudo_isomorphisms() const;

      void
      print_characterisitc_matrix() const;

      void
      print_characterisitc_polynomial() const;

      void
      print_rmts_complemented_rules() const;

      void
      tweak_rules() const;

      void
      update_config();
  };
}

#endif
