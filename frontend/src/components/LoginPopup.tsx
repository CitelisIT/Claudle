import React from "react";
import { Dialog } from "@headlessui/react";
import { UserCircleIcon } from "@heroicons/react/outline";
import { Link } from "react-router-dom";

interface Props {
  loginOpen: boolean;
  setLoginOpen: React.Dispatch<React.SetStateAction<boolean>>;
}

export default function LoginPopup({ loginOpen, setLoginOpen }: Props) {
  return (
    <Dialog
      open={loginOpen}
      onClose={() => setLoginOpen(false)}
      className="fixed inset-0 w-10/12 p-4 m-auto text-gray-200 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl mg:p-8 lg:w-5/12 mx-1/2 h-fit"
    >
      <Dialog.Overlay />
      <div className="flex flex-col justify-center w-full gap-4 p-6 md:gap-12 md:p-16 flex-center">
        <Dialog.Title className="flex flex-col items-center justify-center gap-2 m-2 md:m=4 md:gap-4">
          <UserCircleIcon className="w-10 h-10 lg:h-12 lg:w-12" />
          <span className="text-base font-semibold md:text-lg lg:text-xl ">
            Connexion
          </span>
        </Dialog.Title>
        <Dialog.Description as="div" className="w-full">
          <form
            action="/login"
            className="flex flex-col items-start justify-center w-full gap-8"
          >
            <fieldset className="w-full">
              <label
                htmlFor="username-input"
                className="text-sm font-medium lg:text-xl md:text-lg"
              >
                Nom d'utilisateur
              </label>
              <input
                type="text"
                name="username"
                id="username-input"
                className="w-full p-2 py-2 my-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
              />
            </fieldset>
            <fieldset className="w-full">
              <label
                htmlFor="pwd-input"
                className="text-sm font-medium lg:text-xl md:text-lg"
              >
                Mot de passe
              </label>
              <input
                type="text"
                name="pwd"
                id="pwd-input"
                className="w-full p-2 py-2 my-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
              />
            </fieldset>
            <div className="flex items-center justify-between w-full">
              <Link
                onClick={() => setLoginOpen(false)}
                to="/register"
                className="text-sm text-gray-200 md:text-lg lg:text-xl hover:underline hover:underline-offset-4"
              >
                Créer un compte
              </Link>
              <button
                type="submit"
                className="p-2 text-sm text-green-600 border border-green-600 rounded-lg md:text-lg lg:text-xl"
              >
                Se connecter
              </button>
            </div>
          </form>
        </Dialog.Description>
      </div>
    </Dialog>
  );
}
