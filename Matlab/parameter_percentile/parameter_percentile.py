from scipy import stats, optimize
from math import log, pow
from functools import partial

def normal_parameters(x1, p1, x2, p2):
    "Find parameters for a normal random variable X so that P(X < x1) = p1 and P(X < x2) = p2."
    denom = stats.norm.ppf(p2) - stats.norm.ppf(p1)
    sigma = (x2 - x1) / denom
    mu = (x1*stats.norm.ppf(p2) - x2*stats.norm.ppf(p1)) / denom
    return (mu, sigma)
    
def cauchy_parameters(x1, p1, x2, p2):    
    "Find parameters for a Cauchy random variable X so that P(X < x1) = p1 and P(X < x2) = p2."
    denom = stats.cauchy.ppf(p2) - stats.cauchy.ppf(p1)
    sigma = (x2 - x1) / denom
    mu = (x1*stats.cauchy.ppf(p2) - x2*stats.cauchy.ppf(p1)) / denom
    return (mu, sigma)
	
def weibull_parameters(x1, p1, x2, p2):
    "Find parameters for a Weibull random variable X so that P(X < x1) = p1 and P(X < x2) = p2."
    gamma = (log(-log(1-p2)) - log(-log(1-p1))) / (log(x2) - log(x1))
    beta = x1 / pow(-log(1-p1), 1.0/gamma)	
    return (gamma, beta)
    
def gamma_parameters(x1, p1, x2, p2):
    "Find parameters for a gamma random variable X so that P(X < x1) = p1 and P(X < x2) = p2."
    
    # Standardize so that x1 < x2 and p1 < p2
    if p1 > p2:
        (p1, p2) = (p2, p1)
        (x1, x2) = (x2, x1)
    
    # function to find roots of for gamma distribution parameters
    def objective(alpha):
        return stats.gamma.ppf(p2, alpha) / stats.gamma.ppf(p1, alpha) - x2/x1
    
    # The objective function we're wanting to find a root of is decreasing.
    # We need to find an inverval over which is goes from positive to negative.
    left = right = 1.0
    while objective(left) < 0.0:
        left /= 2
    while objective(right) > 0.0:
        right *= 2
    alpha = optimize.bisect(objective, left, right)
    beta = x1 / stats.gamma.ppf(p1, alpha)

    return (alpha, beta)
    
def inverse_gamma_parameters(x1, p1, x2, p2):
    (shape, scale) = gamma_parameters(1/x1, 1-p1, 1/x2, 1-p2)
    return (shape, 1/scale)

def beta_parameters(x1, p1, x2, p2):
    "Find parameters for a beta random variable X so that P(X < x1) = p1 and P(X < x2) = p2."

    def square(x): 
        return x*x

    def objective(v):
        (a, b) = v
        temp  = square( stats.beta.cdf(x1, a, b) - p1 )
        temp += square( stats.beta.cdf(x2, a, b) - p2 )
        return temp
    
    # arbitrary initial guess of (3, 3) for parameters
    xopt = optimize.fmin(objective, (3, 3))
    return (xopt[0], xopt[1])
	
def test():
    #--------------------------------------------------------------------------
    # Normal distribution
    # Make up a problem.
    p1 = 0.2
    p2 = 0.8
    mu = -3.4
    sigma = 5.6
    x1 = stats.norm.ppf(p1, mu, sigma)
    x2 = stats.norm.ppf(p2, mu, sigma)
    print "Testing normal distribution"
    print "True parameters:       ", mu, sigma
    # Now solve the problem to make sure you get the original parameters back.
    (mu, sigma) = normal_parameters(x1, p1, x2, p2)
    print "Calculated parameters: ", mu, sigma
    print
   
    #--------------------------------------------------------------------------
    # Cauchy distribution
    # Make up a problem.
    p1 = 0.1
    p2 = 0.75
    mu = -3.4
    sigma = 5.6
    x1 = stats.cauchy.ppf(p1, mu, sigma)
    x2 = stats.cauchy.ppf(p2, mu, sigma)
    print "Testing Cauchy distribution"
    print "True parameters:       ", mu, sigma
    # Now solve the problem to make sure you get the original parameters back.
    (mu, sigma) = cauchy_parameters(x1, p1, x2, p2)
    print "Calculated parameters: ", mu, sigma
    print
       
    #--------------------------------------------------------------------------
    # Weibull distribution
    # Make up a problem.
    p1 = 0.2
    p2 = 0.95
    gamma = 2.1
    beta = 3.7
    x1 = stats.exponweib.ppf(p1, 1, gamma, scale=beta)
    x2 = stats.exponweib.ppf(p2, 1, gamma, scale=beta)
    print "Testing Weibull distribution"
    print "True parameters:       ", gamma, beta
    # Now solve the problem to make sure you get the original parameters back.
    (gamma, beta) = weibull_parameters(x1, p1, x2, p2)
    print "Calculated parameters: ", gamma, beta
    print 
    
    #--------------------------------------------------------------------------
    # Gamma distribution
    # Make up a problem.
    p1 = 0.2
    p2 = 0.87
    alpha = 0.4
    beta = 0.86
    
    x1 = stats.gamma.ppf(p1, alpha, scale=beta)
    x2 = stats.gamma.ppf(p2, alpha, scale=beta)
    print "Testing gamma distribution"
    print "True parameters:       ", alpha, beta
    # Now solve the problem to make sure you get the original parameters back.
    (alpha, beta) = gamma_parameters(x1, p1, x2, p2)
    print "Calculated parameters: ", alpha, beta
    print     

    #--------------------------------------------------------------------------
    # Inverse gamma distribution
    # Make up a problem.
    p1 = 0.01
    p2 = 0.38
    alpha = 3.4
    beta = 5.6
    x1 = stats.invgamma.ppf(p1, alpha, scale=beta)
    x2 = stats.invgamma.ppf(p2, alpha, scale=beta)
    print "Testing inverse gamma distribution"
    print "True parameters:       ", alpha, beta
    # Now solve the problem to make sure you get the original parameters back.
    (alpha, beta) = inverse_gamma_parameters(x1, p1, x2, p2)
    print "Calculated parameters: ", alpha, beta
    print    

    #--------------------------------------------------------------------------
    # Beta distribution
    # Make up a problem.
    p1 = 0.1
    p2 = 0.8
    a = 4.7
    b = 2.8
    x1 = stats.beta.ppf(p1, a, b)
    x2 = stats.beta.ppf(p2, a, b)
    print "Testing beta distribution"
    print "True parameters:       ", a, b
    # Now solve the problem to make sure you get the original parameters back.
    (a, b) = beta_parameters(x1, p1, x2, p2)
    print "Calculated parameters: ", a, b
    print    

    
if __name__ == "__main__":
    test()

	
