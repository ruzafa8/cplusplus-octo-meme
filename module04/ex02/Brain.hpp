#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

    public:
        Brain();
        Brain(Brain const &other);
        virtual ~Brain();

        Brain	&operator=(Brain const &other);

		std::string	getIdea(int index) const;
		void		setIdea(int index, std::string idea);

    protected:
        std::string	ideas[100];

};

#endif