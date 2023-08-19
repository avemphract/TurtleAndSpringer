#define GardenComponentId 0b100000
namespace Components{
    class Gardencomponent
    {
    private:
        /* data */
    public:
        int getComponentId() { return GardenComponentId; }
        void resetComponent() {};
    };
}