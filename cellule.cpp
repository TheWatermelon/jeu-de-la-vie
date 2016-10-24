class Cellule {
    private:
        bool alive;
        bool previous;
        int ligne;
        int colonne;

    public:
        Cellule() {
            alive=false;
            previous=false;
        }
  
        void setLigne(int l) {
          ligne = l;
        }
  
        void setColonne(int c) {
          colonne = c;
        }

        void toggleAlive() {
            alive=!alive;
        }
    
        void archive() {
            previous=alive;
        }
    
        bool isPrevious() {
            return previous;
        }

        bool isAlive() {
            return alive;
        }
  
        int update(Cellule** tab, int taille) {
            int dir[8][2] = {
              {-1,0},
              {-1,1},
              {0,1},
              {1,1},
              {1,0},
              {1,-1},
              {0,-1},
              {-1,-1}
            };  
            int count=0, l, c;
          
            for(int i=0; i<8; i++) {
              l=ligne+dir[i][0];
              c=colonne+dir[i][1];
              if(l<0) { l=taille-1; } 
              else if(l==taille) { l=0; }
              if(c<0) { c=taille-1; }
              else if(c==taille) { c=0; }
              
              if(tab[l][c].isPrevious()) { count++; }
            }
            return count;
        }
};