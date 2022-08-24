
typedef char AirportCode[4];

typedef struct NodeTag {
  AirportCode Airport;
  struct NodeTag *Link;
} NodeType;

int main() {
  return 0;
}
