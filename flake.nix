{
  description = "Flake for the MCC project";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs?ref=nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
      in
      {
        devShells.default = with pkgs; mkShell {
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

          hardeningDisable = [ "all" ];
        };
      }
    );
}
