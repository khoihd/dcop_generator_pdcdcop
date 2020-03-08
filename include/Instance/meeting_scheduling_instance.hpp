#ifndef DCOP_GENERATOR_MEETING_SCHEDULING_INSTANCE_HPP
#define DCOP_GENERATOR_MEETING_SCHEDULING_INSTANCE_HPP

#include "instance.hpp"

namespace dcop_generator
{
    class meeting_scheduling_instance : public instance
    {
    public:
        typedef std::shared_ptr<meeting_scheduling_instance> ptr;

        // It generates a number of random instances of tyepe meeting scheduling,
        //
        // The variables denote meetings, whose possible domains represent times in which the
        // meetings can take place. Constraints among variables represents shared participants:
        // i.e., if exists a constraints between two variables x and y, then it means that
        // meeting x and y share a participant. Their time schedule should be different.
        // Attendances preferences are taken into account in the meetings, #modelled as unary
        // constraints.
        // @param nb_meetings The number of Meetings.
        // @param meetings_times The number of elements in range [1...dom_size]
        //        associated to each variable of the problem.
        // @param p1 The constraint network density
        // @param p2 The constraint tightness
        meeting_scheduling_instance(int nb_meetings, int meetings_times, double p1, double p2);

        ~meeting_scheduling_instance();

    protected:
        virtual std::string to_string() const override;

        virtual void add_relation(int arity, double p2, int d_min, int d_max, std::string rel_name) override;
    };
}

#endif //DCOP_GENERATOR_MEETING_SCHEDULING_INSTANCE_HPP
