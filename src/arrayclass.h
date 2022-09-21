class DynArray {
    public:
        DynArray();

        void wertRein(int x, int y, int wert);
        int wertBei(int x, int y);

        void ausgabe();
    
    private:
        int maxX;
        int maxY;
        int **array;
        void vergroessere(int neuesX, int neuesy);
};