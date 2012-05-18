class Density(HermitianOperator):
    # methods not stated here, will be left as is in the current version.
        
    def _eval_args()
        #validate for args to be of type State 
        #if args is some QExpr, we need to expand and see if it evals to a State?

    def doit()
        # fix this, behavior remains same.

    def _represent()
        # fix this, behavior remains same

    def entropy()
      # currently this is a function outside this class.
      # I plan to move this into the class. I see that it was
      # moved out of the class during refactoring.


      ## Other functions that are currently defined under qubitdensity.py
    def reduced_density()
       ## This method can be generic and will be included as part of
       ## the generic density class.

    def entropy_of_entanglement()
       ## This method is also currently under qubitdensity.py, but could
       ## be part of this class


    
       

