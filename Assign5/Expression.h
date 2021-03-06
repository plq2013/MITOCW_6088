/*
 * 6.088 IAP 2010  
 * Assignment #5: Inheritance and Polymorphism
 * 
 * Expression.h
 * Header file for the abstract base class Expression
 */

#ifndef EXPRESSION
#define EXPRESSION

#include <cstdlib>
#include <iostream>

/*
 * Expression
 */
class Expression {

 public: 
  virtual ~Expression() {}
  
  // Returns the result of evaluating this expression.
  virtual float eval() const = 0;

  // Prints the expression. DO NOT evaluate before printing.
  virtual void print() const = 0;  
};


class ConstExpr : public Expression {
public:
	ConstExpr():m_val(0.0)	// ctor
	{
	}

	~ConstExpr()	// dtor
	{
	}

	void print( ) const
	{
		std::cout << m_val;
	}

	float eval( ) const 
	{
		return m_val;
	}

private:
	float m_val;

};


class BinaryExpr : public Expression {
	public:
		BinaryExpr( std::string &input )
		{
			/*std::size_t foundPos;
			if (foundPos = input.find("+"))
			*/
		}

		// virtual implementation
		float eval() const 
		{
			// no checking at unusual cases
			if (op.compare("+") == 0)
				return ( lhs->eval() + rhs->eval() );

			if (op.compare("-") == 0)
				return ( lhs->eval() - rhs->eval() );

			if (op.compare("*") == 0)
				return ( lhs->eval() * rhs->eval() );

			if (op.compare("/") == 0)
				return ( lhs->eval() / rhs->eval() );

			return 0.0;
		}

		void print() const
		{
			lhs->print();
			std::cout << " " << op << " ";
			rhs->print();
		}

	private:
		std::string op;
		Expression	*lhs, *rhs;
};



#endif  // EXPRESSION
