class Circle
{
    public :							//宣告涵式在public
        void SetRadius(double radius);
        double GetRadius();
        double CalculateArea();
        double CalculateDiameter();
        double CalculateCircumference();
    private:							//宣告變數在private
        double _radius;

};