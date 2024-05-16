{
  description = "A very basic flake";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    buildenv = {
      url =
        "git+https://gitlab.lre.epita.fr/tiger/buildenv?ref=master&dir=nix";
      inputs = { nixpkgs.follows = "nixpkgs"; };
    };
  };

  outputs = { self, nixpkgs, buildenv }:
    let
      system = "x86_64-linux";
      pkgs = nixpkgs.legacyPackages.${system};
    in
    {

      packages.x86_64-linux.hello = nixpkgs.legacyPackages.x86_64-linux.hello;

      packages.x86_64-linux.default = self.packages.x86_64-linux.hello;

      devShells.${system}.default = with pkgs; mkShell {
        packages = [
          cmake
          gnumake
          bison
          buildenv.outputs.packages.${system}.reflex
          llvmPackages_18.libcxx
          llvmPackages_18.libcxxStdenv
          llvmPackages_18.libllvm
          llvmPackages_18.libcxxClang
          llvmPackages_18.compiler-rt
          llvmPackages_18.mlir
        ];
      };
    };
}
