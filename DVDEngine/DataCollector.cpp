#include "DataCollector.h"



DataCollector::DataCollector()
{
}


DataCollector::~DataCollector()
{
}
auto DataCollector::getByID(int fID) {
	for (int i = 0; i < (f->getlist().size()); i++)
	{
		if (f->getMovie(i).getID() == fID)
		{
			cout << f->getMovie(i).getDVD_Title() << endl;
		}
	}
};
