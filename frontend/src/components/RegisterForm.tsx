import { UserCircleIcon } from "@heroicons/react/outline";
import React from "react";

export default function RegisterForm() {
  return (
    <div className="flex flex-col items-center justify-center w-full gap-16 p-12 md:p-16">
      <div className="flex flex-col items-center justify-center gap-8">
        <UserCircleIcon className="w-10 h-10 text-gray-200 lg:h-12 lg:w-12" />
        <span className="text-base font-semibold text-gray-200 md:text-lg lg:text-xl">
          Créer un compte
        </span>
      </div>
      <form
        action="/register"
        className="flex flex-col items-start justify-center w-10/12 gap-8 text-gray-200 lg:w-5/12"
      >
        <fieldset className="w-full">
          <label
            htmlFor="username-input"
            className="text-base font-medium lg:text-xl md:text-lg"
          >
            Nom d'utilisateur
          </label>
          <input
            type="text"
            name="username"
            id="username-input"
            className="w-full p-2 py-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
          />
        </fieldset>
        <fieldset className="w-full">
          <label
            htmlFor="pwd-input"
            className="text-base font-medium lg:text-xl md:text-lg"
          >
            Mot de passe
          </label>
          <input
            type="password"
            name="pwd"
            id="pwd-input"
            className="w-full p-2 py-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
          />
        </fieldset>
        <fieldset className="w-full">
          <label
            htmlFor="pwd-bis-input"
            className="text-base font-medium lg:text-xl md:text-lg"
          >
            Répéter le mot de passe
          </label>
          <input
            type="password"
            name="pwd-bis"
            id="pwd-bis-input"
            className="w-full p-2 py-2 bg-gray-900 border border-gray-600 rounded-lg md:my-4"
          />
        </fieldset>
        <div className="flex items-center justify-end w-full">
          <button
            type="submit"
            className="p-2 text-base text-green-600 border border-green-600 rounded-lg md:text-lg lg:text-xl"
          >
            Créer un compte
          </button>
        </div>
      </form>
    </div>
  );
}
