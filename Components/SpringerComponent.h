#define SpringerComponentId 0b1000000

namespace Components{
    class SpringerComponent
    {
    private:
        /* data */
    public:
        int getComponentId() { return SpringerComponentId; }
        void resetComponent() {};
    };
    
    SpringerComponent::SpringerComponent(/* args */)
    {
    }
    
    SpringerComponent::~SpringerComponent()
    {
    }
    
}