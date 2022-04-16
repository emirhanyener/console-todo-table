using namespace std;

class ILog{
	protected:
	string content;
	public:
	virtual string getLog() = 0;
};
