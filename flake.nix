{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {
      devShells.${system}.default = with pkgs; mkShell {
        packages = [
          # programs
          gcc14
          gdb
          cmake
          gnumake
          bison
          re-flex
          clang-tools

          # libs
          gtest
        ];
      };
    };
}
