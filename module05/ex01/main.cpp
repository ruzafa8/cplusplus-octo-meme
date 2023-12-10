#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	{
		Form formA("Formulario para ser jarredios", 0, 1, 1);
		Bureaucrat juanan("Juanan", 1);
		juanan.signForm(formA);
	}
}