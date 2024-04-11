class Simulator:
    """Simulator base class.
    """

    def __init__(self):
        pass

    def solve_velocity(init_cond, boundary_cond, fluid_prop):
        """ Fill init_cond with simulation result.
        """
        pass

    def solve_traj(
            init_cond,
            boundary_cond,
            fluid_prop,
            x,
            y
    ):
        """Output trajectory of a particle given its initial position.
        """
        pass