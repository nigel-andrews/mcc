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

      packages.x86_64-linux.hello = nixpkgs.legacyPackages.x86_64-linux.hello;

      packages.x86_64-linux.default = self.packages.x86_64-linux.hello;

      devShells.${system}.default = with pkgs; mkShell {
        packages = [
          # programs
          gcc14
          gdb
          cmake
          gnumake
          bison
          re-flex.dev
          clang-tools

          # libs
          gtest
        ];
      };
    };
}
