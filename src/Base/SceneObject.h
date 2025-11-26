#include <vector>
#include <IProperty.h>

template<typename T>
class SceneObject{
    public:
        SceneObject();
        ~SceneObject();

        void AddProperty(IProperty&);
        void RemoveProperty(IProperty&);
        T GetProperty();

        void DrawObject();
    
    private:
        std::vector<IProperty> m_Properties;

};