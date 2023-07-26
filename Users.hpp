namespace one {

struct UserI {
  virtual void BasicBitch() = 0;
};

struct AdminI {
  virtual void PrivilegedBitch() = 0;
};

struct User : public UserI {
  void BasicBitch() override;
};

struct Admin : public UserI, public AdminI {
  void BasicBitch() override;
  void PrivilegedBitch() override;
};

// polimorfizm możliwy, ale przy jego użyciu admin ma tylko podstawowe funkcje

};  // namespace one

namespace two {

struct FullI {
  virtual void BasicBitch() = 0;
  virtual void PrivilegedBitch() = 0;
};

struct DenyPrivileges : public FullI {
  void PrivilegedBitch() final {}
};

struct User : public DenyPrivileges {
  void BasicBitch() override;
};

struct Admin : public FullI {
  void BasicBitch() override;
  void PrivilegedBitch() override;
};

// rozdział interfejsu złamany
// trzeba implementować niedostępne funkcje
// kompletne bagno przy większej liczbie poziomów usera

};  // namespace two