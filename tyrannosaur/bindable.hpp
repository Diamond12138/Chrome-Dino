#ifndef bindable_hpp
#define bindable_hpp

namespace Tyrannosaur
{
	class Bindable
	{
		public:
			virtual void genObject() = 0;
			virtual void bindObject() = 0;
	};
}

#endif
